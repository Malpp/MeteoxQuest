#pragma once
#include "stdafx.h"
#include "game_object.h"
#include "weapon.h"

class Character : public GameObject
{
public:
	Character(
		const sf::Vector2f& pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		const int no_frames,
		const int no_states,
		const float frame_delay,
		const float move_speed,
		const int life,
		Color color,
		const int damage);
	~Character();
	void update(const float delta_time, LevelBase* level) override;
	virtual void down();
	virtual void up();
	virtual void left();
	virtual void right();
	virtual void fire(LevelBase* level);
protected:
	Weapon* weapon_;
private:
	float movespeed_;
};
