#include "stdafx.h"
#include "powerup.h"

PowerUp::PowerUp(const sf::Vector2f& pos,
				const float angle,
				sf::Texture* texture,
				const sf::Vector2f& size,
				const int no_frames,
				const int no_states,
				const float frame_delay,
				const int life,
				const Color color,
				const int damage,
				const GameType type)
	: NonCharacter(pos,
					angle,
					texture,
					size,
					no_frames,
					no_states,
					frame_delay,
					life,
					color,
					damage,
					type)
{
	
}
