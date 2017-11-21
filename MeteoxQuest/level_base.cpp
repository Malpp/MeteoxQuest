#include "stdafx.h"
#include "level_base.h"
#include "Game.h"

LevelBase::LevelBase( sf::RenderWindow* window, const std::string& background_texture, float scroll_speed )
	: Scene( window ), player_( sf::Vector2f( 100, 100 ), 0, resource_handler_.add_texture( "player.png" ) )
{
	scroll_speed_ = scroll_speed;
	sf::Texture* bg_texture = resource_handler_.add_texture( background_texture );
	for (int i = 0; i < 2; ++i)
	{
		background_sprites_[i] = sf::Sprite( *bg_texture );
	}
	background_sprites_[1].setPosition( Game::GAME_WIDTH, 0 );
}

void LevelBase::input()
{
	while (window_->pollEvent( event ))
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
				change_scene( EXIT );
				break;
			default:
				break;
			}
		}
		manage_input( event );
	}
}

void LevelBase::update( float delta_time )
{
	if (sf::Keyboard::isKeyPressed( sf::Keyboard::W ))
		player_.up();

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::A ))
		player_.left();

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::S ))
		player_.down();

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::D ))
		player_.right();

	player_.update( delta_time );

	for (int i = 0; i < 2; ++i)
	{

		sf::Vector2f pos = background_sprites_[i].getPosition();
		if (pos.x < -Game::GAME_WIDTH)
			pos.x += Game::GAME_WIDTH * 2;
		pos.x -= scroll_speed_ * delta_time;
		background_sprites_[i].setPosition( pos );
	}
}

void LevelBase::draw()
{
	window_->clear();

	for (int i = 0; i < 2; ++i)
	{
		window_->draw( background_sprites_[i] );
	}
	window_->draw( player_ );

	window_->display();
}

void LevelBase::manage_input( sf::Event event )
{}
