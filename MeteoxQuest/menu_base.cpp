#include "stdafx.h"
#include "menu_base.h"
#include "menu_element.h"
#include "Game.h"
#include <archives/binary.hpp>

MenuBase::MenuBase(
	sf::RenderWindow* window,
	const Scene::Scenes scene_to_exit)
	: Scene(window)
{
	MenuElement::focused_element_ = nullptr;
	background_sprite_.setTexture(
								 *resource_handler_.add_texture("menu_background.jpg"));
	exit_scene_ = scene_to_exit;
	error_string_ = "";
}

void MenuBase::input()
{
	menu_manager_.pre_input();
	while(window_->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			close();
		}

		if(event.type == sf::Event::KeyPressed)
		{
			switch(event.key.code)
			{
				case sf::Keyboard::Escape:
					change_scene(exit_scene_);
					break;
				default:
					break;
			}
		}
		menu_manager_.input(event, window_);
	}
}

void MenuBase::draw()
{
	window_->draw(background_sprite_);

	menu_manager_.draw(window_);
}

void MenuBase::update(float delta_time)
{
}
