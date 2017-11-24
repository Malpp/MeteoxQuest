#include "stdafx.h"
#include "ken_enemy.h"
#include "Game.h"
#include "level_base.h"
#include "ken_weapon.h"

sf::Texture* KenEnemy::texture_ = Game::resource_handler_.add_texture( "ken_enemy.png" );
const sf::Vector2f KenEnemy::size_ = sf::Vector2f( 62 * 2, 80 * 2 );
const float KenEnemy::movespeed_ = 200;
const float KenEnemy::frame_delay_ = 0.1f;

KenEnemy::KenEnemy( const sf::Vector2f& pos, const float angle )
	: Enemy( pos, angle, texture_, size_, no_frames_, COUNT, frame_delay_, movespeed_ )
{
	weapon_ = new KenWeapon;
	state_ = WALKING;
	fire_timer_ = 0;
}

void KenEnemy::update( const float delta_time, LevelBase* level )
{
	if(state_ == WALKING)
	{
		left();
		if (weapon_->can_fire())
		{
			frame_ = 0;
			state_ = FIRING;
		}
	}

	if(state_ == FIRING)
	{
		if(frame_ == 4)
			fire( level );

		if (frame_ == 5)
			state_ = WALKING;
	}
	Enemy::update( delta_time, level );
}
