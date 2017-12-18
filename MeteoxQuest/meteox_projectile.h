#pragma once
#include "stdafx.h"
#include "enemy_projectile.h"

class MeteoxProjectile : public EnemyProjectile
{
public:
	MeteoxProjectile(
		const sf::Vector2f& pos,
		const float angle,
		const sf::Vector2f& direction,
		const Color color);
	static sf::Texture* texture;
private:
	static const sf::Vector2f size_;
	static const int no_frames_ = 1;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
};