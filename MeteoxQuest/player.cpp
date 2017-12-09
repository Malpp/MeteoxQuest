#include "stdafx.h"
#include "player.h"
#include "level_base.h"
#include "Game.h"
#include "heart_weapon.h"
#include "projectile.h"
#include "bomb.h"
#include "emp_bomb.h"

sf::Texture* Player::texture_ = Game::resource_handler_.add_texture(
																	 "player.png");
const sf::Vector2f Player::size_ = sf::Vector2f(140, 80);
const float Player::movespeed_ = 600;
const float Player::frame_delay_ = 0.1f;
const float Player::max_idle_time_ = 0.1f;
const float Player::dash_duration_ = 0.15f;
const float Player::dash_speed_ = 1000;
const float Player::dash_cooldown_ = 2;

unsigned Player::get_score() const
{
	return score_;
}

void Player::add_score(const int score_to_add)
{
	score_ += score_to_add;
}

int Player::get_life() const
{
	return life_;
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
	weapons.push_back(new HeartWeapon);
	weapon_ = weapons.front();
	score_ = 0;
	last_state_ = state_;
	dashing_ = false;
	dash_timer_ = 0;
	dash_cooldown_timer_ = 0;
	dash_ready_ = true;
	bomb_launched_ = false;
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		fire(level);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
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

	Character::update(delta_time, level);
	notify_all_observers();
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
		//take_damage( other );
	}

	if(dynamic_cast<Enemy*>(other))
	{
		//despawn();
	}

	if(const auto bomb = dynamic_cast<Bomb*>(other))
	{
		if(std::find(bombs_.begin(), bombs_.end(), bomb) == bombs_.end())
		{
			bombs_.push_back(bomb);
			std::cout << "added bomb\n";
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
		last_state_ = state_;
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
	if(no_commands == 2)
	{
		const unsigned last_command = commands.rbegin()[0]->move_;
		if(last_command != command_manager_.last_removed_)
			return;
		dash_direction_.x = 0;
		dash_direction_.y = 0;
		const unsigned second_last_command = commands.rbegin()[1]->move_;

		//Dash left
		if(last_command == LEFT && second_last_command
			== RIGHT)
		{
			dash_direction_.x = -1;
			command_manager_.remove_commands(no_commands);
		}
			//Dash right
		else if(last_command == RIGHT &&
			second_last_command == LEFT)
		{
			dash_direction_.x = 1;
			command_manager_.remove_commands(no_commands);
		}
			//Dash up
		else if(last_command == UP &&
			second_last_command == DOWN)
		{
			dash_direction_.y = -1;
			command_manager_.remove_commands(no_commands);
		}
			//Dash down
		else if(last_command == DOWN &&
			second_last_command == UP)
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
}
