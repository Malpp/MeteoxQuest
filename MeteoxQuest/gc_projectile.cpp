#include "stdafx.h"
#include "gc_projectile.h"
#include "Game.h"

sf::Texture* GCProjectile::texture_ = Game::resource_handler_.add_texture("gc_projectile.png");
const sf::Vector2f GCProjectile::size_ = sf::Vector2f(48, 44);
const float GCProjectile::movespeed_ = 1000;
const float GCProjectile::frame_delay_ = 0.2f;

GCProjectile::GCProjectile(const sf::Vector2f& pos, const float angle, const sf::Vector2f& direction)
	: EnemyProjectile(pos, angle, texture_, size_, no_frames_, no_states_, frame_delay_, direction * movespeed_)
{
}
