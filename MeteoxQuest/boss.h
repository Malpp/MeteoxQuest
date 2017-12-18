#pragma once
#include "enemy.h"

class Boss : public Enemy
{
public:
	enum BossState
	{
		NORMAL,
		ENRAGED,
		COUNT
	};
	Boss(
		const sf::Vector2f& pos,
		float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		float move_speed,
		int base_life);

	void update(const float delta_time, LevelBase* level) override;
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
	void generate_random_direction();
	static const unsigned drop_rate_ = 0;
	static const unsigned score_worth_ = 0;
	static const int no_states_ = COUNT;
	static const int no_frames_ = 1;
	static const int frame_delay_ = 1;
	sf::Vector2f direction_;
	float pos_move_timer_;
};
