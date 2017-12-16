#include "stdafx.h"
#include "player.h"
#include "level_base.h"
#include "Game.h"
#include "heart_weapon.h"
#include "projectile.h"
#include "bomb.h"
#include "emp_bomb.h"
#include "mario_weapon.h"

sf::Texture* Player::texture_ = Game::resource_handler_.add_texture(
	"player.png");
const sf::Vector2f Player::size_ = sf::Vector2f(140, 80);
const float Player::movespeed_ = 600;
const float Player::frame_delay_ = 0.1f;
const float Player::max_idle_time_ = 0.1f;
const float Player::dash_duration_ = 0.15f;
const float Player::dash_speed_ = 1000;
const float Player::dash_cooldown_ = 2;
const float Player::weapon_switch_cooldown_ = 0.1f;

unsigned Player::get_score() const
{
	return score_;
}

void Player::add_score(const int score_to_add)
{
	score_ += score_to_add;
}

Player::Player(const sf::Vector2f& pos, const float angle)
	: Character(pos,
	            angle,
	            texture_,
	            size_,
	            no_frames_,
	            COUNT,
	            frame_delay_,
	            movespeed_,
	            base_life_,
	            NONE,
	            base_damage_,
	            PLAYER)
	, Subject()
{
	weapons_.push_back(new HeartWeapon);
	weapons_.push_back(new MarioWeapon);
	weapon_equipped_ = weapons_.begin();
	weapon_ = *weapon_equipped_;
	weapon_switch_timer_ = 0;
	weapon_switch_ready_ = true;
	score_ = 0;
	last_state_ = state_;
	dashing_ = false;
	dash_timer_ = 0;
	dash_cooldown_timer_ = 0;
	dash_ready_ = true;
	bomb_launched_ = false;
	shields_.push(new Shield(this));
}

Player::~Player()
{
	auto iterator = weapons_.begin();
	do
	{
		if(*iterator != weapon_)
			delete (*iterator);
		++iterator;
	} while(iterator != weapons_.end());
	if(*iterator != weapon_)
		delete (*iterator);
	weapons_.clear();

	while(shields_.size() != 0)
	{
		delete shields_.top();
		shields_.pop();
	}
}

void Player::update(const float delta_time, LevelBase* level)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		up();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		left();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		down();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		right();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && weapon_switch_ready_)
	{
		switch_weapon_left();
		weapon_switch_ready_ = false;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && weapon_switch_ready_)
	{
		switch_weapon_right();
		weapon_switch_ready_ = false;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		fire(level);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		if(!bomb_launched_ && bombs_.size() > 0)
		{
			if(bombs_.back()->launch(this))
			{
				bomb_launched_ = true;
				bombs_.pop_back();
			}
		}
	}
	else
	{
		bomb_launched_ = false;
	}
	if(velocity_.x == 0 && velocity_.y == 0)
		state_ = IDLE;

	do_dashes(delta_time);

	if(dashing_)
	{
		dash_timer_ += delta_time;
		if(dash_timer_ > dash_duration_)
		{
			dash_timer_ = 0;
			dashing_ = false;
			dash_direction_.x = 0;
			dash_direction_.y = 0;
		}
		else
		{
			velocity_ += dash_direction_ * dash_speed_;
		}
	}
	else
	{
		if(!dash_ready_)
		{
			dash_cooldown_timer_ += delta_time;
			if(dash_cooldown_timer_ > dash_cooldown_)
			{
				dash_ready_ = true;
				dash_cooldown_timer_ = 0;
			}
		}
	}

	if(!weapon_switch_ready_)
	{
		weapon_switch_timer_ += delta_time;
		if(weapon_switch_timer_ > weapon_switch_cooldown_)
		{
			weapon_switch_ready_ = true;
			weapon_switch_timer_ = 0;
		}
	}

	Character::update(delta_time, level);
	notify_all_observers(delta_time);
}

void Player::up()
{
	state_ = UP;
	Character::up();
}

void Player::down()
{
	state_ = DOWN;
	Character::down();
}

void Player::left()
{
	state_ = LEFT;
	Character::left();
}

void Player::right()
{
	state_ = RIGHT;
	Character::right();
}

void Player::on_death(LevelBase* level)
{
}

void Player::add_powerup(const PowerUp::PowerUpType power_up)
{
}

void Player::handle_collision(GameObject* other, LevelBase* level)
{
	if(dynamic_cast<Projectile*>(other) && dynamic_cast<Projectile*>(other)->
		get_type() == Projectile::ENEMY)
	{
		take_damage(other, level);
	}

	if(dynamic_cast<Enemy*>(other))
	{
		take_damage(other, level);
	}

	if(const auto bomb = dynamic_cast<Bomb*>(other))
	{
		if(std::find(bombs_.begin(), bombs_.end(), bomb) == bombs_.end())
		{
			bombs_.push_back(bomb);
		}
	}
}

void Player::do_dashes(const float delta_time)
{
	//If new command, insert it
	if(state_ != IDLE && last_state_ != state_)
	{
		dashing_ = false;
		command_manager_.add(new Command(state_));
		idle_timer_ = 0;
	}
	else
	{
		//If the player stays idle to too long
		//reset the last_removed_
		if(state_ == IDLE)
		{
			idle_timer_ += delta_time;
			if(idle_timer_ > max_idle_time_)
			{
				command_manager_.last_removed_ = IDLE;
			}
		}
	}

	std::vector<Command*>& commands = command_manager_.commands_;

	command_manager_.update(delta_time);

	//If only 2 keys remain in the commands
	//This is so the player must hold a direction before being able to dash
	//in that direction
	const int no_commands = commands.size();
	if(no_commands >= 2)
	{
		const unsigned last_command = commands.rbegin()[0]->move_;
		const unsigned second_last_command = commands.rbegin()[1]->move_;
		dash_direction_.x = 0;
		dash_direction_.y = 0;

		//Dash left
		if(last_command == LEFT && second_last_command
			== LEFT)
		{
			dash_direction_.x = -1;
			command_manager_.remove_commands(no_commands);
		}
			//Dash right
		else if(last_command == RIGHT &&
			second_last_command == RIGHT)
		{
			dash_direction_.x = 1;
			command_manager_.remove_commands(no_commands);
		}
			//Dash up
		else if(last_command == UP &&
			second_last_command == UP)
		{
			dash_direction_.y = -1;
			command_manager_.remove_commands(no_commands);
		}
			//Dash down
		else if(last_command == DOWN &&
			second_last_command == DOWN)
		{
			dash_direction_.y = 1;
			command_manager_.remove_commands(no_commands);
		}

		//Only dash if ready
		if((dash_direction_.x || dash_direction_.y) && dash_ready_)
		{
			dash_ready_ = false;
			dashing_ = true;
		}
	}
	last_state_ = state_;
}

void Player::switch_weapon_right()
{
	if(weapon_ != weapons_.back())
	{
		weapon_ = nullptr;
		++weapon_equipped_;
		weapon_ = *weapon_equipped_;
	}
}

int Player::take_damage(
	const GameObject* object,
	LevelBase* level,
	const int damage)
{
	int damage_remaining = object->get_damage();
	if(shields_.size() > 0)
	{
		while(shields_.size() > 0 && (damage_remaining = shields_.top()->
			  take_damage(
			  object,
			  level,
			  damage_remaining)
			  ) != -1)
		{
			if(shields_.top()->get_life() < 1)
			{
				std::cout << "popped\n";
				delete shields_.top();
				shields_.pop();
			}
		}
	}
	damage_remaining = damage_remaining == -1 ? 0 : damage_remaining;
	return GameObject::take_damage(object, level, damage_remaining);
}

Shield* Player::get_shield()
{
	return shields_.top();
}

bool Player::shield_exists() const
{
	return shields_.size() > 0;
}

int Player::get_no_shields() const
{
	return shields_.size();
}

void Player::switch_weapon_left()
{
	if(weapon_ != weapons_.front())
	{
		weapon_ = nullptr;
		--weapon_equipped_;
		weapon_ = *weapon_equipped_;
	}
}

void Player::fire(LevelBase* level)
{
	if (weapon_->get_ammo() == 0)
	{
		weapon_ = nullptr;
		weapons_.erase(weapon_equipped_);
		weapon_equipped_ = weapons_.begin();
		weapon_ = *weapon_equipped_;
	}
	else
	{
		Character::fire(level);
	}
}
