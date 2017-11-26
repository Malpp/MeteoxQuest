#pragma once
#include "stdafx.h"
#include "menu_element.h"

class MenuManager
{
public:
	~MenuManager();
	void pre_input();
	void input(sf::Event& event, sf::RenderWindow* window);
	void update(float delta_time);
	void draw(sf::RenderWindow* window);
	void next();
	void back();
	void add_to_menu(MenuElement* to_add);
private:
	int get_current_focued();
	void fix_current_focus(int* current_idx) const;
	std::vector<MenuElement*> elements_;
};
