#include "stdafx.h"
#include "explosive_projectile.h"

sf::Texture* ExplosiveBlast::texture_;
const sf::Vector2f ExplosiveBlast::size_ = sf::Vector2f( 600, 600 );
const float ExplosiveBlast::movespeed_ = 0;
const float ExplosiveBlast::frame_delay_ = 0.008f;

ExplosiveBlast::ExplosiveBlast( const sf::Vector2f& pos,
	const float angle )
	: PlayerProjectile( pos,
		angle,
		texture_,
		size_,
		no_frames_,
		no_states_,
		frame_delay_,
		sf::Vector2f(),
		movespeed_ )
{}

void ExplosiveBlast::update( const float delta_time, LevelBase* level )
{
	state_ = frame_ / no_frames_;

	if(state_ >= no_states_ - 1)
	{
		despawn();
	}
	PlayerProjectile::update( delta_time, level );
}

void ExplosiveBlast::on_death( LevelBase* level )
{}