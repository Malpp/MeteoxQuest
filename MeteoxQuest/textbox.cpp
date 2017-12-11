#include "stdafx.h"
#include "textbox.h"
#include "Game.h"

sf::Color Textbox::back_text_color_ = sf::Color(100, 100, 100);
sf::Vector2f Textbox::textbox_size_ = sf::Vector2f(100, 12);

Textbox::Textbox(
	sf::Vector2f& pos,
	sf::Vector2f& size,
	std::string back_text)
	: MenuElement(pos, size, true)
	, text_("", Game::font, 8)
	, back_text_(back_text, Game::font, 8)
{
	box_ = sf::RectangleShape(size);
	box_.setPosition(pos);
	box_.setFillColor(sf::Color::White);
	box_.setOutlineThickness(2);
	box_.setOutlineColor(default_color_);
	text_.setFillColor(sf::Color::Black);
	text_.setPosition(pos_ + size_ * 0.5f);
	back_text_.setOrigin(
						 back_text_.getCharacterSize() * back_text_.getString().getSize() *
						 0.5f,
						 back_text_.getCharacterSize() * 0.5f);
	back_text_.setPosition(pos_ + size_ * 0.5f);
	back_text_.setFillColor(back_text_color_);
	max_text_size_ = (int)(click_box_.width / text_.getCharacterSize());
}

void Textbox::draw(sf::RenderWindow* window)
{
	if(focused_element_ == this)
		box_.setOutlineColor(focus_color_);
	else if(is_hovering_)
		box_.setOutlineColor(hover_color_);
	else
		box_.setOutlineColor(default_color_);

	window->draw(box_);
	window->draw(text_);

	if(current_string_.getSize() == 0)
		window->draw(back_text_);
}

void Textbox::handle_input(sf::Event& event, sf::RenderWindow* window)
{
	if(focused_element_ == this)
	{
		switch(event.type)
		{
			case sf::Event::TextEntered:
				{
					char to_add = static_cast<char>(event.text.unicode);
					if(to_add < 128 && to_add > 31)
					{
						current_string_ += std::toupper(to_add, std::locale());
					}
					break;
				}
			case sf::Event::KeyPressed:
				switch(event.key.code)
				{
					case sf::Keyboard::BackSpace:
						current_string_ = current_string_.substring(
																	 0,
																	 current_string_.getSize() - 1);
						break;
					case sf::Keyboard::Return:
						is_active_ = true;
						break;
				}
				break;
		}

		text_.setString(current_string_);
		center_text();
		keep_text_inside();
	}
}

std::string Textbox::get_text() const
{
	return current_string_;
}

void Textbox::set_text(const std::string& text)
{
	current_string_ = text;
	text_.setString(current_string_);
	center_text();
	keep_text_inside();
}

void Textbox::center_text()
{
	text_.setOrigin(
					 text_.getCharacterSize() * text_.getString().getSize() * 0.5f,
					 text_.getCharacterSize() * 0.5f);
}

void Textbox::keep_text_inside()
{
	int current_char_size = text_.getCharacterSize();
	int text_length = text_.getString().getSize();
	while(current_char_size * text_length > click_box_.width)
	{
		current_char_size--;
	};

	if(max_text_size_ - 1 < text_length)
	{
		while(current_char_size * text_length < click_box_.width - text_.
			getCharacterSize())
		{
			current_char_size++;
		};
	}
	text_.setCharacterSize(current_char_size);
}
