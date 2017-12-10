#pragma once
#include "projectile.h"

class PlayerProjectile : public Projectile
{
public:
	PlayerProjectile(
		const sf::Vector2f& pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		const int no_frames,
		const int no_states,
		const float frame_delay,
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

	PlayerProjectile(
		const sf::Vector2f& pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		const int no_frames,
		const int no_states,
		const float frame_delay,
		const sf::Vector2f& direction,
		const float movespeed,
		const float damage)
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
					 movespeed,
					 damage)
	{
	}
};
#pragma once
