#include "stdafx.h"
#include "lol_projectile.h"
#include "Game.h"

const std::string LOLProjectile::texture_name_ = "Projectiles/LOL/";
sf::Texture* LOLProjectile::textures_[] = {
	Game::resource_handler_.
	add_texture(texture_name_ + "red.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "green.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "blue.png")
};
const sf::Vector2f LOLProjectile::size_ = sf::Vector2f(48, 44);
const float LOLProjectile::movespeed_ = 1000;
const float LOLProjectile::frame_delay_ = 0.2f;

LOLProjectile::LOLProjectile(
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
		direction * movespeed_,
		color)
{
}
