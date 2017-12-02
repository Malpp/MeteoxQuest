#include "stdafx.h"
#include "main_menu.h"
#include "list.h"

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

void MainMenu::update(float delta_time)
{
	list<int> list;
	menu_manager_.update(delta_time);
	if(play_button_->get_active())
		change_scene(Scene::Scenes::GAME);
	MenuBase::update(delta_time);
}
