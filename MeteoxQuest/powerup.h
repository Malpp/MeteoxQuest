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
		float frame_delay );
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
	void on_death(LevelBase* level) override;
	static const int powerup_life_ = 1;
	static const int powerup_damage_ = 1;
};
