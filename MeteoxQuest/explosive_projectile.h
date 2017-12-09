#pragma once
#include "player_projectile.h"

class ExplosiveBlast : public PlayerProjectile
{
public:
	ExplosiveBlast( const sf::Vector2f& pos,
		float angle );
	void update( const float delta_time, LevelBase* level ) override;
	static sf::Texture* texture_;
	void on_death( LevelBase* level ) override;
private:
	static const std::string texture_name_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 9;
	static const int no_states_ = 9;
	static const float movespeed_;
	static const float frame_delay_;
};
