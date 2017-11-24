#include "stdafx.h"
#include "orc_projectile.h"
#include "Game.h"

sf::Texture* OrcProjectile::texture_ = Game::resource_handler_.add_texture( "orc_projectile.png" );
const sf::Vector2f OrcProjectile::size_ = sf::Vector2f( 48, 44 );
const float OrcProjectile::movespeed_ = 2000;
const float OrcProjectile::frame_delay_ = 0.2f;

OrcProjectile::OrcProjectile(const sf::Vector2f& pos, float angle, const sf::Vector2f& direction)
	: Projectile( pos, angle, texture_, size_, no_frames_, no_states_, frame_delay_, direction * movespeed_ )
{
}
