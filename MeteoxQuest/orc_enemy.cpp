#include "stdafx.h"
#include "orc_enemy.h"
#include "Game.h"
#include "orc_weapon.h"
#include <valarray>

sf::Texture* OrcEnemy::texture_ = Game::resource_handler_.add_texture( "orc_enemy.png" );
const sf::Vector2f OrcEnemy::size_ = sf::Vector2f( 80, 83 );
const float OrcEnemy::movespeed_ = 600;
const float OrcEnemy::frame_delay_ = 0.1f;

OrcEnemy::OrcEnemy( const sf::Vector2f& pos, const float angle )
	: Enemy( pos, angle, texture_, size_, no_frames_, no_states_, frame_delay_, movespeed_ )
{
	weapon_ = new OrcWeapon;
}

void OrcEnemy::update( const float delta_time, LevelBase* level )
{
	left();
	velocity_.y = 2* movespeed_ * std::sin(frame_ * 0.65f);
	fire( level );
	Enemy::update( delta_time, level );
}