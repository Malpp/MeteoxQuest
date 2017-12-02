#pragma once
#include "non_character.h"

class PowerUp : public NonCharacter
{
public:

	PowerUp( const sf::Vector2f& pos,
		float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		int no_frames,
		int no_states,
		float frame_delay,
		int life,
		Color color,
		int damage,
		GameType type );
};
