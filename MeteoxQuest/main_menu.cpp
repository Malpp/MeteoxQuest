#include "stdafx.h"
#include "main_menu.h"


MainMenu::MainMenu(sf::RenderWindow* window)
	:MenuBase(window, Scene::Scenes::EXIT)
{
	play_button_ = new Button(sf::Vector2f(200, 200), sf::Vector2f(400, 200), "PLAY THE GAME BOI");
	whatever_button_ = new Button(sf::Vector2f(700, 200), sf::Vector2f(400, 200), "IT DOES NOTHING");
	cool_button_ = new Button(sf::Vector2f(1200, 200), sf::Vector2f(400, 200), "THAT BUTTON IS PRETTY COOL");

	menu_manager_.add_to_menu(play_button_);
	menu_manager_.add_to_menu(whatever_button_);
	menu_manager_.add_to_menu(cool_button_);
}


MainMenu::~MainMenu()
{

}

void MainMenu::update(float delta_time)
{
	menu_manager_.update(delta_time);
	if (play_button_->get_active())
		change_scene(Scene::Scenes::GAME);
	MenuBase::update(delta_time);
}