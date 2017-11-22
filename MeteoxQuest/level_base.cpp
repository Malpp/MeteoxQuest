#include "stdafx.h"
#include "level_base.h"
#include "Game.h"
#include "GC_enemy.h"

LevelBase::LevelBase( sf::RenderWindow* window, const std::string& background_texture, float scroll_speed )
	: Scene( window ), player_( sf::Vector2f( 100, Game::GAME_HEIGHT * 0.5f ), 0, resource_handler_.add_texture( "player.png" ) )
{
	scroll_speed_ = scroll_speed;
	sf::Texture* bg_texture = resource_handler_.add_texture( background_texture );
	for (int i = 0; i < 2; ++i)
	{
		background_sprites_[i] = sf::Sprite( *bg_texture );
	}
	background_sprites_[1].setPosition( Game::GAME_WIDTH, 0 );
	add_game_object( new GCEnemy( sf::Vector2f(1300, 300 ), 0) );
}

LevelBase::~LevelBase()
{
	for (GameObject* object : objects_)
	{
		delete object;
	}
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

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space ))
		player_.fire(this);

	player_.update( delta_time );

	for (int i = objects_.size() - 1; i >= 0; --i)
	{
		objects_[i]->update( delta_time );
		if(objects_[i]->get_despawn())
		{
			delete objects_[i];
			objects_.erase( objects_.begin() + i );
		}
	}

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
	for (GameObject* object : objects_)
	{
		window_->draw( *object );
	}
	window_->draw( player_ );

	window_->display();
}

void LevelBase::manage_input( sf::Event event )
{}

void LevelBase::add_game_object(GameObject* object )
{
	objects_.push_back( object );
}
