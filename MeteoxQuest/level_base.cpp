#include "stdafx.h"
#include "level_base.h"
#include "Game.h"
#include "GC_enemy.h"
#include <sstream>

LevelBase::LevelBase(sf::RenderWindow* window, const std::string& background_texture, float scroll_speed)
	: Scene(window), player_(sf::Vector2f(100, Game::GAME_HEIGHT * 0.5f), 0)
{
	scroll_speed_ = scroll_speed;
	sf::Texture* bg_texture = resource_handler_.add_texture(background_texture);
	for (int i = 0; i < 2; ++i)
	{
		background_sprites_[i] = sf::Sprite(*bg_texture);
	}
	background_sprites_[1].setPosition(Game::GAME_WIDTH, 0);
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
	player_.update(delta_time, this);

	for (int i = objects_.size() - 1; i >= 0; --i)
	{
		objects_[i]->update(delta_time, this);
		if (objects_[i]->get_despawn())
		{
			delete objects_[i];
			objects_.erase(objects_.begin() + i);
		}
	}

	for (int i = 0; i < 2; ++i)
	{

		sf::Vector2f pos = background_sprites_[i].getPosition();
		if (pos.x < -Game::GAME_WIDTH)
			pos.x += Game::GAME_WIDTH * 2;
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
	window_->draw(player_);

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