#include "stdafx.h"
#include "orc_projectile.h"
#include "Game.h"

const std::string OrcProjectile::texture_name_ = "Projectiles/Orc/";
sf::Texture* OrcProjectile::textures_[] = {
	Game::resource_handler_.
	add_texture(texture_name_ + "red.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "green.png"),
	Game::resource_handler_.
	add_texture(texture_name_ + "blue.png")
};
const sf::Vector2f OrcProjectile::size_ = sf::Vector2f(48, 44);
const float OrcProjectile::movespeed_ = 2000;
const float OrcProjectile::frame_delay_ = 0.2f;

OrcProjectile::OrcProjectile(
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
