#pragma once
#include "projectile.h"

class EnemyProjectile : public Projectile
{
public:
	EnemyProjectile(const sf::Vector2f& pos, float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay, const sf::Vector2f& direction)
		: Projectile(pos, angle, texture, size, no_frames, no_states, frame_delay, direction, ENEMY)
	{
	}
};
