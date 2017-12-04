#include "stdafx.h"
#include "gc_projectile.h"
#include "Game.h"

const std::string GCProjectile::texture_name_ = "Projectiles/GC/";
sf::Texture* GCProjectile::textures_[] = {
	Game::resource_handler_.
	add_texture(texture_name_ + "red.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "green.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "blue.png")
};
const sf::Vector2f GCProjectile::size_ = sf::Vector2f(48, 44);
const float GCProjectile::movespeed_ = 1000;
const float GCProjectile::frame_delay_ = 0.2f;

GCProjectile::GCProjectile(
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
