#pragma once
#include "menu_base.h"
#include "button.h"

class MainMenu : public MenuBase
{
public:
	MainMenu(sf::RenderWindow* window);
	~MainMenu();
	void update(float delta_time) override;
private:
	Button* play_button_;
};
