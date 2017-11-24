#pragma once
#include "stdafx.h"
#include "character.h"

class LevelBase;

class Player : public Character
{
public:
	enum PlayerState
	{
		IDLE,
		LEFT,
		RIGHT,
		UP,
		DOWN,
		COUNT
	};
	Player( const sf::Vector2f& pos, const float angle);

	void update(const float delta_time, LevelBase* level) override;
	void up() override;
	void down() override;
	void left() override;
	void right() override;
private:
	static sf::Texture* texture_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 4;
	static const float movespeed_;
	static const float frame_delay_;
};
