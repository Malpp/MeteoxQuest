#include "stdafx.h"
#include "Game.h"
#include "cloud9_enemy.h"
#include "level_base.h"
#include "cloud9_weapon.h"

const std::string Cloud9Enemy::texture_name_ = "Enemies/Cloud9/";
sf::Texture* Cloud9Enemy::textures_[3];
const sf::Vector2f Cloud9Enemy::size_ = sf::Vector2f(220, 157);
const float Cloud9Enemy::movespeed_ = 100;
const float Cloud9Enemy::frame_delay_ = 0.1f;

Cloud9Enemy::Cloud9Enemy(
	const sf::Vector2f& pos,
	const float angle,
	const Color color)
	: Enemy(pos,
	        angle,
	        textures_[color],
	        size_,
	        no_frames_,
	        no_states_,
	        frame_delay_,
	        movespeed_,
	        base_life_,
	        color,
	        score_worth_,
			drop_rate_)
{
	weapon_ = new Cloud9Weapon(color);
}

void Cloud9Enemy::update(const float delta_time, LevelBase* level)
{
	left();
	fire(level);
	Enemy::update(delta_time, level);
}
