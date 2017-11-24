#pragma once
#include "projectile.h"

class OrcProjectile : public Projectile
{
public:
	OrcProjectile( const sf::Vector2f& pos, float angle, const sf::Vector2f& direction );
private:
	static sf::Texture* texture_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 1;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
};