#pragma once
#include "powerup.h"

class ShieldPowerup : public PowerUp
{
public:

	ShieldPowerup(
		const sf::Vector2f& pos,
		float angle);
	static sf::Texture* texture_;
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
	static const sf::Vector2f size_;
	static const int no_frames_ = 1;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
};
