#pragma once
#include "stdafx.h"
#include "projectile.h"

class KenProjectile : public Projectile
{
public:
	KenProjectile( const sf::Vector2f& pos, float angle, const sf::Vector2f& direction );
private:
	static sf::Texture* texture_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 2;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
};
