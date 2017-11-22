#include "stdafx.h"
#include "main_menu.h"


MainMenu::MainMenu(sf::RenderWindow* window)
	:MenuBase(window, Scene::Scenes::EXIT)
{
	play_button_ = new Button(sf::Vector2f(200, 200), sf::Vector2f(200, 200), "PLAY THE GAME BOI");
	whatever_button_ = new Button(sf::Vector2f(500, 200), sf::Vector2f(200, 200), "PLAY THE GAME BOI");
	cool_button_ = new Button(sf::Vector2f(800, 200), sf::Vector2f(200, 200), "PLAY THE GAME BOI");

	menu_manager_.add_to_menu(play_button_);
	menu_manager_.add_to_menu(whatever_button_);
	menu_manager_.add_to_menu(cool_button_);
}


MainMenu::~MainMenu()
{

}

void MainMenu::update(float delta_time)
{
	MenuBase::update(delta_time);
}