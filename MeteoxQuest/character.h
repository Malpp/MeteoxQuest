#pragma once
#include "stdafx.h"
#include "game_object.h"
#include "weapon.h"

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
	Character( const sf::Vector2f& pos, const float angle, sf::Texture* texture, const sf::Vector2f& size, const int no_frames, const int no_states, const float frame_delay, const float move_speed, const float fire_speed );
	~Character();
	void update(const float delta_time, LevelBase* level) override;
	virtual void up();
	virtual void down();
	virtual void left();
	virtual void right();
	virtual void fire(LevelBase* level);
protected:
	Weapon* weapon_;
private:
	float movespeed_;
	float fire_speed_;
	float fire_timer_;
	bool  can_fire_;
};
