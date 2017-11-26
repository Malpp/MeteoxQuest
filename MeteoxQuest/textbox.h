#pragma once
#include "stdafx.h"
#include "menu_element.h"

class Textbox : public MenuElement
{
public:
	Textbox(
		sf::Vector2f& pos,
		sf::Vector2f& size,
		std::string back_text = "");
	void draw(sf::RenderWindow* window) override;
	void handle_input(sf::Event& event, sf::RenderWindow* window) override;
	std::string get_text() const;
	static const int textbox_font_size = 24;
	static sf::Color back_text_color_;
	static sf::Vector2f textbox_size_;
	void set_text(const std::string& text);
private:
	void center_text();
	void keep_text_inside();
	sf::RectangleShape box_;
	sf::Text text_;
	sf::Text back_text_;
	sf::String current_string_;
	int max_text_size_;
};
