#include "stdafx.h"
#include "powerup.h"

PowerUp::PowerUp(const sf::Vector2f& pos,
				const float angle,
				sf::Texture* texture,
				const sf::Vector2f& size,
				const int no_frames,
				const int no_states,
				const float frame_delay)
	: NonCharacter(pos,
					angle,
					texture,
					size,
					no_frames,
					no_states,
					frame_delay,
					powerup_life_,
					NONE,
					powerup_damage_,
					PLAYER)
{
}

void PowerUp::handle_collision(GameObject* other, LevelBase* level)
{
}

void PowerUp::on_death(LevelBase* level)
{
}
