#pragma once
#include "stdafx.h"
#include "enemy.h"

class GCEnemy : public Enemy
{
public:
	GCEnemy( const sf::Vector2f& pos, float angle );
	void update(const float delta_time) override;
	static sf::Texture* texture_;
private:
	static const sf::Vector2f size_;
	static const int no_frames_ = 1;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
};
