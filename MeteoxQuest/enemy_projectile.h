#pragma once
#include "projectile.h"

class EnemyProjectile : public Projectile
{
public:
	EnemyProjectile(
		const sf::Vector2f& pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		const int no_frames,
		const int no_states,
		const float frame_delay,
		const sf::Vector2f& direction,
		const Color color,
		const float movespeed)
		: Projectile(pos,
					angle,
					texture,
					size,
					no_frames,
					no_states,
					frame_delay,
					direction,
					ENEMY,
					color,
					movespeed)
	{
	}
};
