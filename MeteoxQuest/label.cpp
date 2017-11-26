#include "stdafx.h"
#include "label.h"
#include "Game.h"

Label::Label(
	sf::Vector2f& pos,
	const std::string& text,
	const int char_size)
	: MenuElement(pos,
	              sf::Vector2f(char_size * text.size(), char_size),
	              false)//, text_(text, Game::font, char_size)
{
	text_.setFillColor(sf::Color::White);
	text_.setPosition(pos);
}

void Label::draw(sf::RenderWindow* window)
{
	window->draw(text_);
}

void Label::handle_input(sf::Event& event, sf::RenderWindow* window)
{
}
