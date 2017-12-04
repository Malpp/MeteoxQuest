#pragma once
#include "powerup.h"

class Bomb : public PowerUp
{
public:

	Bomb( const sf::Vector2f& pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		const int no_frames,
		const int no_states,
		const float frame_delay,
		const float movespeed);
	void update(const float delta_time, LevelBase* level) override;
};
