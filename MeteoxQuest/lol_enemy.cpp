#include "stdafx.h"
#include "lol_enemy.h"
#include "lol_weapon.h"
#include "Game.h"
#include "level_base.h"


const std::string LOLEnemy::texture_name_ = "Enemies/Orc/";
sf::Texture* LOLEnemy::textures_[] = {
	Game::resource_handler_.
	add_texture(texture_name_ + "red.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "green.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "blue.png")
};
const sf::Vector2f LOLEnemy::size_ = sf::Vector2f(80, 83);
const float	LOLEnemy::movespeed_ = 600;
const float LOLEnemy::frame_delay_ = 0.1f;

LOLEnemy::LOLEnemy(const sf::Vector2f& pos, const float angle, const Color color)
	:Enemy(pos,
		angle,
		textures_[color],
		size_,
		no_frames_,
		no_states_,
		frame_delay_,
		movespeed_,
		base_life_,
		color)
{
	weapon_ = new LOLWeapon(color);
}

void LOLEnemy::update(const float delta_time, LevelBase* level)
{
	left();
	velocity_.y = movespeed_;
	fire(level);
	Enemy::update(delta_time, level);
}