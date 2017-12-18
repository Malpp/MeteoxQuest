#include "stdafx.h"
#include "meteox_projectile.h"
#include "Game.h"

sf::Texture* MeteoxProjectile::texture = Game::resource_handler_.
		add_texture("Projectiles/Meteox/meteox.png");
const sf::Vector2f MeteoxProjectile::size_ = sf::Vector2f(64, 90);
const float MeteoxProjectile::movespeed_ = 800;
const float MeteoxProjectile::frame_delay_ = 0.2f;

MeteoxProjectile::MeteoxProjectile(
	const sf::Vector2f& pos,
	const float angle,
	const sf::Vector2f& direction,
	const Color color)
	: EnemyProjectile(pos,
	                  angle,
	                  texture,
	                  size_,
	                  no_frames_,
	                  no_states_,
	                  frame_delay_,
	                  direction,
	                  color,
	                  movespeed_)
{
	set_color_to_match();
}
