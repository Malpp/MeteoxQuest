#include "stdafx.h"
#include "level_base.h"
#include "Game.h"
#include "GC_enemy.h"
#include "orc_enemy.h"
#include "ken_enemy.h"
#include <fstream>
#include "src/json.hpp"
#include "meteox1.h"
#include "meteox3.h"
#include "meteox2.h"
#include "meteox4.h"
#include "cloud9_enemy.h"

const float LevelBase::combo_time_ = 3;

LevelBase::LevelBase(
	sf::RenderWindow* window,
	sf::Texture* texture,
	const float scroll_speed)
	: Scene(window)
	, combo_(1)
	, combo_timer_(0)
{
	player_ = new Player(sf::Vector2f(100, Game::GAME_HEIGHT * 0.5f), 0);
	player_->add_observer(&hud);
	add_observer(&hud);
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
	if (player_->get_life() <= 0)
		change_scene(END);

	//Update waves
	if(!waves_.empty())
	{
		Wave* current_wave = waves_.front();
		current_wave->update(delta_time);

		if(nbr_enemies_ == 0 && current_wave->get_delay() > 5)
		{
			current_wave->set_delay(5);
		}

		if(current_wave->get_delay() <= 0)
		{
			current_wave->spawn_enemies(this);
			nbr_enemies_ += current_wave->get_size();
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
			if(const auto weapon = dynamic_cast<Enemy*>(objects_[i]))
				--nbr_enemies_;
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
		player_->get_shield()->update(delta_time, this);

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

	//Update sounds
	update_sounds();

	//Update combo
	if(combo_ > 1)
	{
		combo_timer_ += delta_time;
		if(combo_timer_ > combo_time_)
		{
			combo_ *= 0.5f;
			combo_timer_ = 0;
		}
	}

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
			else if (type == "CLOUD9")
				wave->add_enemy(new Cloud9Enemy(
					sf::Vector2f(posX * Game::GAME_WIDTH,
						posY * Game::GAME_HEIGHT),
					0,
					GameObject::generate_random_color()));
			else if(type == "METEOX1")
				wave->add_enemy(new Meteox1(sf::Vector2f(posX * Game::GAME_WIDTH,
				                                         posY * Game::GAME_HEIGHT),
				                            0));
			else if(type == "METEOX2")
				wave->add_enemy(new Meteox2(sf::Vector2f(posX * Game::GAME_WIDTH,
				                                         posY * Game::GAME_HEIGHT),
				                            0));
			else if(type == "METEOX3")
				wave->add_enemy(new Meteox3(sf::Vector2f(posX * Game::GAME_WIDTH,
				                                         posY * Game::GAME_HEIGHT),
				                            0));
			else if(type == "METEOX4")
				wave->add_enemy(new Meteox4(sf::Vector2f(posX * Game::GAME_WIDTH,
				                                         posY * Game::GAME_HEIGHT),
				                            0));
		}

		waves_.push_back(wave);
	}
	return true;
}

void LevelBase::add_score(const int score_to_add)
{
	player_->add_score(score_to_add * combo_);
	combo_ *= 2;
	combo_timer_ = 0;
}

Player* LevelBase::get_player() const
{
	return player_;
}

void LevelBase::play_sound(sf::SoundBuffer* buffer)
{
	sound_queue_.push_back(sf::Sound(*buffer));
	sound_queue_.back().play();
}

int LevelBase::get_combo() const
{
	return combo_;
}

void LevelBase::update_sounds()
{
	if(sound_queue_.size() > 0)
	{
		if(sound_queue_.front().getStatus() == sf::SoundSource::Stopped)
		{
			sound_queue_.pop_front();
		}
	}
}
