#include "stdafx.h"
#include "GC_enemy.h"
#include "Game.h"
#include "level_base.h"
#include "gc_weapon.h"

const std::string GCEnemy::texture_name_ = "Enemies/GC/";
sf::Texture* GCEnemy::textures_[] = {
	Game::resource_handler_.
	add_texture(texture_name_ + "red.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "green.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "blue.png")
};
const sf::Vector2f GCEnemy::size_ = sf::Vector2f(105, 75);
const float GCEnemy::movespeed_ = 600;
const float GCEnemy::frame_delay_ = 0.1f;

GCEnemy::GCEnemy(
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
			score_worth_)
{
	weapon_ = new GCWeapon(color_);
}

void GCEnemy::update(const float delta_time, LevelBase* level)
{
	left();
	fire(level);
	Enemy::update(delta_time, level);
}
