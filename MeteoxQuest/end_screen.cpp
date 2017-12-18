#include "stdafx.h"
#include "end_screen.h"
#include "game.h"


EndScreen::EndScreen(sf::RenderWindow* window)
	:Scene(window),
	victory_text_("Victory!", Game::font, 50)
{
	victory_text_.setPosition(0.4f * Game::CAMARA_WIDTH, 0.2f * Game::CAMERA_HEIGHT);
	victory_sprite_.setTexture(
		*resource_handler_.add_texture("meteox_victory_screen.png"));
	victory_sprite_.setPosition(Game::CAMARA_WIDTH * 0.4f, Game::CAMERA_HEIGHT * 0.33f);
	death_sprite_.setTexture(
		*resource_handler_.add_texture("death_screen.jpg"));
	death_sprite_.setPosition(Game::CAMARA_WIDTH * 0.35f, Game::CAMERA_HEIGHT * 0.33f);
}


EndScreen::~EndScreen()
{

}

void EndScreen::update(float delta_time)
{
	
}

void EndScreen::draw()
{
	if (!Game::get_player_alive())
		window_->draw(death_sprite_);
	else
	{
		window_->draw(victory_sprite_);
		window_->draw(victory_text_);
	}		
}

void EndScreen::input()
{
	while (window_->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				change_scene(MENU);
				break;
			default:
				break;
			}
		}
	}
}


