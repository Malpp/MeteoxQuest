#include "stdafx.h"
#include "level_base.h"
#include "Game.h"
#include "GC_enemy.h"
#include <sstream>

LevelBase::LevelBase(sf::RenderWindow* window, sf::Texture* texture, float scroll_speed)
	: Scene(window)
{
	player_ = new Player( sf::Vector2f( 100, Game::GAME_HEIGHT * 0.5f ), 0 );
	add_game_object( player_ );
	scroll_speed_ = scroll_speed;
	background_size_ = static_cast<sf::Vector2f>(texture->getSize());
	for (int i = 0; i < 2; ++i)
	{
		background_sprites_[i] = sf::Sprite(*texture );
	}
	background_sprites_[1].setPosition( background_size_.x - 1, 0);
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
				change_scene(EXIT);
				break;
			default:
				break;
			}
		}
		manage_input(event);
	}
}

void LevelBase::update(float delta_time)
{

	for (int i = objects_.size() - 1; i >= 0; --i)
	{
		objects_[i]->update(delta_time, this);

		for (int j = i - 1; j >= 0; --j)
		{
			objects_[i]->collision_test( objects_[j] );
		}

		if (objects_[i]->get_despawn())
		{
			delete objects_[i];
			objects_.erase(objects_.begin() + i);
		}
	}

	for (int i = 0; i < 2; ++i)
	{

		sf::Vector2f pos = background_sprites_[i].getPosition();
		if (pos.x < -background_size_.x)
		{
			sf::Vector2f other_pos = background_sprites_[!i].getPosition();
			pos.x = other_pos.x + background_size_.x - 1;			
		}
		pos.x -= scroll_speed_ * delta_time;
		background_sprites_[i].setPosition(pos);
	}

	fps_timer_ += delta_time;

	if (fps_timer_ > 1)
	{
		std::ostringstream oss;
		oss << "Meteox Quest | " << fps_ << " fps";
		window_->setTitle(oss.str());
		fps_timer_ = 0;
		fps_ = 0;
	}
	++fps_;
}

void LevelBase::draw()
{
	window_->clear();

	for (int i = 0; i < 2; ++i)
	{
		window_->draw(background_sprites_[i]);
	}
	for (GameObject* object : objects_)
	{
		window_->draw(*object);
	}

	window_->display();
}

void LevelBase::manage_input(sf::Event event)
{}

void LevelBase::add_game_object(GameObject* object)
{
	objects_.push_back(object);
}

bool LevelBase::loadLevel(const std::string path )
{
	return true;
}