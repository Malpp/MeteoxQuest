#include "stdafx.h"
#include "button.h"
#include "Game.h"
#include "textbox.h"

sf::Color Button::button_color_ = sf::Color( 200, 200, 200 );
const sf::Vector2f Button::button_size = sf::Vector2f(70, 12);

Button::Button( sf::Vector2f& pos, sf::Vector2f& size, std::string button_text )
	: MenuElement( pos, size, true )//, text_( button_text, Game::font, Textbox::textbox_font_size )
{
	box_ = sf::RectangleShape( size );
	box_.setPosition( pos );
	box_.setFillColor( button_color_ );
	box_.setOutlineThickness( 2 );
	box_.setOutlineColor( default_color_ );
	text_.setFillColor( sf::Color::Black );
	text_.setOrigin( button_text.size() * Textbox::textbox_font_size * 0.5f, Textbox::textbox_font_size * 0.5f );
	text_.setPosition( pos_ + size * 0.5f );
}

void Button::draw( sf::RenderWindow* window )
{
	if (focused_element_ == this)
		box_.setOutlineColor( focus_color_ );
	else if (is_hovering_)
		box_.setOutlineColor( hover_color_ );
	else
		box_.setOutlineColor( default_color_ );

	window->draw( box_ );
	window->draw( text_ );
}

void Button::handle_input( sf::Event& event, sf::RenderWindow* window )
{
	if (focused_element_ == this)
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Return:
				is_active_ = true;
				break;
			}
			break;
		case sf::Event::MouseButtonReleased:
			is_active_ = true;
			break;
		}
	}
}
