#include "stdafx.h"
#include "main_menu.h"
#include "textbox.h"

MainMenu::MainMenu(sf::RenderWindow* window)
	: MenuBase(window, Scene::Scenes::EXIT)
{
	play_button_ = new Button(sf::Vector2f(200, 200),
	                          sf::Vector2f(500, 200),
	                          "PLAY THE GAME BOI");

	menu_manager_.add_to_menu(play_button_);
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(const float delta_time)
{
	menu_manager_.update(delta_time);
	if(play_button_->get_active())
		change_scene(Scene::Scenes::LEVEL1);
	MenuBase::update(delta_time);
}
