#pragma once
#include "projectile.h"

class PlayerProjectile : public Projectile
{
public:
	PlayerProjectile(
		const sf::Vector2f& pos,
		float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		int no_frames,
		int no_states,
		float frame_delay,
		const sf::Vector2f& direction,
		const float movespeed)
		: Projectile(pos,
					angle,
					texture,
					size,
					no_frames,
					no_states,
					frame_delay,
					direction,
					PLAYER,
					NONE,
					movespeed)
	{
	}
};
#pragma once
