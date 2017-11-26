#pragma once
#include "stdafx.h"
#include "menu_element.h"

class Label : public MenuElement
{
public:
	Label(
		sf::Vector2f& pos,
		const std::string& text,
		const int char_size = 8);
	void draw(sf::RenderWindow* window) override;
	void handle_input(sf::Event& event, sf::RenderWindow* window) override;
private:
	sf::Text text_;
};
