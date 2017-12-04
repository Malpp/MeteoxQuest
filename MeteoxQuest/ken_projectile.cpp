#include "stdafx.h"
#include "Game.h"
#include "ken_projectile.h"

const std::string KenProjectile::texture_name_ = "Projectiles/Ken/";
sf::Texture* KenProjectile::textures_[] = {
	Game::resource_handler_.
	add_texture(texture_name_ + "red.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "green.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "blue.png")
};
const sf::Vector2f KenProjectile::size_ = sf::Vector2f(192 * 2, 162 * 2);
const float KenProjectile::movespeed_ = 2500;
const float KenProjectile::frame_delay_ = 0.2f;

KenProjectile::KenProjectile(
	const sf::Vector2f& pos,
	const float angle,
	const sf::Vector2f& direction,
	const Color color)
	: EnemyProjectile(pos,
					angle,
					textures_[color],
					size_,
					no_frames_,
					no_states_,
					frame_delay_,
					direction,
					color,
					movespeed_)
{
}
