#include "stdafx.h"
#include "mario_projectile.h"
#include "Game.h"
#include "helper.h"

sf::Texture* MarioProjectile::texture_ = Game::resource_handler_.
		add_texture("mario_projectile.png");
const sf::Vector2f MarioProjectile::size_ = sf::Vector2f(32, 32);
const float MarioProjectile::movespeed_ = 1000;
const float MarioProjectile::frame_delay_ = 0.2f;

MarioProjectile::MarioProjectile(const sf::Vector2f& pos,
								const float angle,
								const sf::Vector2f& direction)
	: PlayerProjectile(pos,
						angle,
						texture_,
						size_,
						no_frames_,
						no_states_,
						frame_delay_,
						direction,
						movespeed_)
{
	state_ = Helper::generateRandInt( 0, Count - 1 );
}
