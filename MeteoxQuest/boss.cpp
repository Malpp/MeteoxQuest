#include "stdafx.h"
#include "boss.h"
#include "meteox_weapon.h"
#include "projectile.h"
#include "helper.h"
#include "Game.h"

Boss::Boss(
	const sf::Vector2f& pos,
	const float angle,
	sf::Texture* texture,
	const sf::Vector2f& size,
	const float move_speed,
	const int base_life)
	: Enemy(
		pos,
		angle,
		texture,
		size,
		no_frames_,
		no_states_,
		frame_delay_,
		move_speed,
		base_life,
		Color::RANDOM,
		score_worth_,
		drop_rate_)
	, pos_move_timer_(0)
	, direction_(0, 0)
{
	weapon_ = new MeteoxWeapon(RANDOM);
}

void Boss::update(const float delta_time, LevelBase* level)
{
	fire(level);
	pos_move_timer_ -= delta_time;
	if(pos_move_timer_ < 0)
	{
		generate_random_direction();
	}
	velocity_ = direction_;
	if(life_ < 15)
		state_ = ENRAGED;
	Enemy::update(delta_time, level);
}

void Boss::handle_collision(GameObject* other, LevelBase* level)
{
	if(dynamic_cast<Projectile*>(other) && dynamic_cast<Projectile*>(other)->
		get_type() == Projectile::PLAYER)
	{
		take_damage(other, level);
	}
}

void Boss::generate_random_direction()
{
	direction_ = Helper::movePointByAngle(movespeed_ + ((state_==ENRAGED) ? 50 : 0),
	                                      Helper::angleBetweenTwoPoints(
		                                      getPosition(),
		                                      sf::Vector2f(
			                                      Helper::generateRandInt(
				                                      Game::GAME_WIDTH * 0.5f,
				                                      Game::GAME_WIDTH -
				                                      half_texture_size_.x),
			                                      Helper::generateRandInt(
				                                      0,
				                                      Game::GAME_HEIGHT))));
	pos_move_timer_ = 1;
}
