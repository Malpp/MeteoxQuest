#pragma once
#include "powerup.h"

class EmpBomb : public PowerUp
{
public:
	EmpBomb(const sf::Vector2f& pos,
			const float angle);
	void update(const float delta_time, LevelBase* level) override;
private:
	static sf::Texture* texture_;
	static const std::string texture_name_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 1;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
};
