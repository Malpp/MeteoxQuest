#include "stdafx.h"
#include "level_base.h"
#include "Game.h"
#include "GC_enemy.h"
#include "orc_enemy.h"
#include "ken_enemy.h"
#include <fstream>
#include "src/json.hpp"

LevelBase::LevelBase(
	sf::RenderWindow* window,
	sf::Texture* texture,
	const float scroll_speed)
	: Scene(window)
{
	player_ = new Player(sf::Vector2f(100, Game::GAME_HEIGHT * 0.5f), 0);
	player_->add_observer(&hud);
	add_observer( &hud );
	add_game_object(player_);
	scroll_speed_ = scroll_speed;
	background_size_ = static_cast<sf::Vector2f>(texture->getSize());
	for(int i = 0; i < 2; ++i)
	{
		background_sprites_[i] = sf::Sprite(*texture);
	}
	background_sprites_[1].setPosition(background_size_.x - 1, 0);
}

LevelBase::~LevelBase()
{
	for(GameObject* object : objects_)
	{
		delete object;
	}

	while(waves_.size() != 0)
	{
		delete waves_.front();
		waves_.pop_front();
	}
}

void LevelBase::input()
{
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
					change_scene(EXIT);
					break;
				default:
					break;
			}
		}
		manage_input(event);
	}
}

void LevelBase::update(const float delta_time)
{
	//Update waves
	if(!waves_.empty())
	{
		Wave* current_wave = waves_.front();
		current_wave->update(delta_time);

		if(current_wave->get_delay() <= 0)
		{
			current_wave->spawn_enemies(this);
			delete waves_.front();
			waves_.pop_front();
		}
	}

	//Update all game objects
	for(int i = objects_.size() - 1; i >= 0; --i)
	{
		objects_[i]->update(delta_time, this);

		for(int j = i - 1; j >= 0; --j)
		{
			objects_[i]->collision_test(objects_[j], this);
		}

		if(objects_[i]->get_despawn())
		{
			delete objects_[i];
			objects_.erase(objects_.begin() + i);
		}
	}

	//Update background
	for(int i = 0; i < 2; ++i)
	{
		sf::Vector2f pos = background_sprites_[i].getPosition();
		if(pos.x < -background_size_.x)
		{
			//											Look at this, !i
			//											It's legit
			sf::Vector2f other_pos = background_sprites_[!i].getPosition();
			pos.x = other_pos.x + background_size_.x - 1;
		}
		pos.x -= scroll_speed_ * delta_time;
		background_sprites_[i].setPosition(pos);
	}

	//Update shield
	if(player_->shield_exists())
		player_->get_shield()->update(delta_time);

	//Update FPS
	fps_timer_ += delta_time;
	if(fps_timer_ > 1)
	{
		std::ostringstream oss;
		oss << "Meteox Quest | " << fps_ << " fps";
		window_->setTitle(oss.str());
		fps_timer_ = 0;
		fps_ = 0;
	}
	++fps_;

	//REEEEEEEEEEEEEE
	notify_all_observers(delta_time);
}

void LevelBase::draw()
{
	for(int i = 0; i < 2; ++i)
	{
		window_->draw(background_sprites_[i]);
	}
	for(GameObject* object : objects_)
	{
		window_->draw(*object);
	}

	if(player_->shield_exists())
		window_->draw(*player_->get_shield());

	hud.draw(window_);
}

void LevelBase::manage_input(sf::Event event)
{
}

void LevelBase::add_game_object(GameObject* object)
{
	objects_.push_back(object);
}

bool LevelBase::load_level(const std::string path)
{
	std::ifstream filestream(path);
	nlohmann::json data;
	filestream >> data;

	for(auto i : data["Enemies"])
	{
		int delay = i["delay"];
		size_t size = i["enemies_to_spawn"].size();

		Wave* wave = new Wave(size, delay);

		for(int j = 0; j < size; ++j)
		{
			std::string type = i["enemies_to_spawn"][j]["type"];
			float posX = i["enemies_to_spawn"][j]["posX"];
			float posY = i["enemies_to_spawn"][j]["posY"];

			if(posY == -1)
				posY = (float)rand() / RAND_MAX;

			if(type == "GC")
				wave->add_enemy(new GCEnemy(
											 sf::Vector2f(posX * Game::GAME_WIDTH,
														posY * Game::GAME_HEIGHT),
											 0,
											 GameObject::generate_random_color()));
			else if(type == "SMORC")
				wave->add_enemy(new OrcEnemy(
											 sf::Vector2f(posX * Game::GAME_WIDTH,
														posY * Game::GAME_HEIGHT),
											 0,
											 GameObject::generate_random_color()));
			else if(type == "KEN")
				wave->add_enemy(new KenEnemy(
											 sf::Vector2f(posX * Game::GAME_WIDTH,
														posY * Game::GAME_HEIGHT),
											 0,
											 GameObject::generate_random_color()));
		}

		waves_.push_back(wave);
	}

	return true;
}

void LevelBase::add_score(const int score_to_add) const
{
	player_->add_score(score_to_add);
}

Player* LevelBase::get_player() const
{
	return player_;
}
