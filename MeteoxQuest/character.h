#pragma once
#include "stdafx.h"
#include "game_object.h"

class Character : public GameObject
{
public:
	enum CharacterState
	{
		IDLE,
		LEFT,
		RIGHT,
		UP,
		DOWN,
		COUNT
	};
	Character( const sf::Vector2f& pos, float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay, float move_speed );
	void update(const float delta_time) override;
	virtual void up();
	virtual void down();
	virtual void left();
	virtual void right();
private:
	float movespeed_;
};
