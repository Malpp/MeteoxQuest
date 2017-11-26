#pragma once
#include "stdafx.h"

class MenuElement
{
public:
	MenuElement(sf::Vector2f& pos, sf::Vector2f& size, bool is_focusable);
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void update(float delta_time);
	static MenuElement* focused_element_;
	void input(sf::Event& event, sf::RenderWindow* window);
	void pre_input();
	virtual void handle_input(sf::Event& event, sf::RenderWindow* window) = 0;
	static sf::Color default_color_;
	static sf::Color hover_color_;
	static sf::Color focus_color_;
	bool get_active() const;
	bool is_focusable() const;
protected:
	sf::Vector2f pos_;
	sf::Vector2f size_;
	sf::FloatRect click_box_;
	bool is_hovering_;
	bool is_focusable_;
	bool is_active_;
};
