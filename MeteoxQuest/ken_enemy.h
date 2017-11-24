#pragma once
#include "stdafx.h"
#include "enemy.h"

class KenEnemy : public Enemy
{
public:
	enum KenState
	{
		WALKING,
		FIRING,
		COUNT
	};
	KenEnemy( const sf::Vector2f& pos, const float angle );
	void update( const float delta_time, LevelBase* level ) override;
	static sf::Texture* texture_;
private:
	static const sf::Vector2f size_;
	static const int no_frames_ = 5;
	static const float movespeed_;
	static const float frame_delay_;
	float fire_timer_;
};
