#include "stdafx.h"
#include "orc_enemy.h"
#include "Game.h"
#include "orc_weapon.h"
#include <valarray>

const std::string OrcEnemy::texture_name_ = "Enemies/Orc/";
sf::Texture* OrcEnemy::textures_[] = {
	Game::resource_handler_.
	add_texture(texture_name_ + "red.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "green.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "blue.png")
};
const sf::Vector2f OrcEnemy::size_ = sf::Vector2f(80, 83);
const float OrcEnemy::movespeed_ = 600;
const float OrcEnemy::frame_delay_ = 0.1f;

OrcEnemy::OrcEnemy(const sf::Vector2f& pos, const float angle, const Color color)
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
	weapon_ = new OrcWeapon(color_);
}

void OrcEnemy::update(const float delta_time, LevelBase* level)
{
	left();
	velocity_.y = 2 * movespeed_ * std::sin(frame_ * 0.65f);
	fire(level);
	Enemy::update(delta_time, level);
}
