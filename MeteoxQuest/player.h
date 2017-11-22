#pragma once
#include "stdafx.h"
#include "character.h"

class LevelBase;

class Player : public Character
{
public:
	Player( const sf::Vector2f& pos, float angle, sf::Texture* texture );

	void update(const float delta_time) override;
	void up() override;
	void down() override;
	void left() override;
	void right() override;
	void fire(LevelBase* level);
private:
	static const sf::Vector2f size_;
	static const int no_frames_ = 4;
	static const float movespeed_;
	static const float frame_delay_;
	static const float fire_speed_;
	float fire_timer_;
	bool  can_fire_;
};
