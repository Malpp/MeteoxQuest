#pragma once
#include "stdafx.h"
#include "character.h"

class Enemy : public Character
{
public:
	Enemy(
		const sf::Vector2f& pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		const int no_frames,
		const int no_states,
		const float frame_delay,
		const float move_speed,
		const int base_life,
		const Color color);
	void on_death() override;
protected:
	void handle_collision(GameObject* other) override;
	bool is_at_edge() override;
	void handle_edge() override;
};
