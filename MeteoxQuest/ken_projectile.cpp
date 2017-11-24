#include "stdafx.h"
#include "Game.h"
#include "ken_projectile.h"

sf::Texture* KenProjectile::texture_ = Game::resource_handler_.add_texture( "ken_projectile.png" );
const sf::Vector2f KenProjectile::size_ = sf::Vector2f( 192 * 2, 162 * 2 );
const float KenProjectile::movespeed_ = 2500;
const float KenProjectile::frame_delay_ = 0.2f;

KenProjectile::KenProjectile( const sf::Vector2f& pos, const float angle, const sf::Vector2f& direction )
	: Projectile( pos, angle, texture_, size_, no_frames_, no_states_, frame_delay_, direction * movespeed_ )
{}
