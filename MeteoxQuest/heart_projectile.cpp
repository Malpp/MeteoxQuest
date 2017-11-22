#include "stdafx.h"
#include "heart_projectile.h"
#include "Game.h"

sf::Texture* HeartProjectile::texture_ = Game::resource_handler_.add_texture("heart.png");
const sf::Vector2f HeartProjectile::size_ = sf::Vector2f( 48, 44 );
const float HeartProjectile::movespeed_ = 1000;
const float HeartProjectile::frame_delay_ = 0.2f;

HeartProjectile::HeartProjectile(const sf::Vector2f& pos, float angle, const sf::Vector2f& direction)
	: Projectile( pos, angle, texture_, size_, no_frames_, no_states_, frame_delay_, direction * movespeed_ )
{

}
