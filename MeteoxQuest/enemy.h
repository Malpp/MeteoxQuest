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
		const Color color,
		const unsigned int score_worth);
	void on_death(LevelBase* level) override;
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
	bool is_at_edge() override;
	void handle_edge() override;
private:
	static const int base_damage_ = 1;
	unsigned int score_worth_;
};
