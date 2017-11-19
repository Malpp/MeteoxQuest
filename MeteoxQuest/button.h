#pragma once
#include "stdafx.h"
#include "menu_element.h"

class Button : public MenuElement
{
public:
	Button(sf::Vector2f& pos, sf::Vector2f& size, std::string button_text);
	void draw(sf::RenderWindow* window) override;
	void handle_input(sf::Event& event, sf::RenderWindow* window) override;
	static const sf::Vector2f button_size;
private:
	sf::RectangleShape box_;
	sf::Text text_;
	static sf::Color button_color_;
};