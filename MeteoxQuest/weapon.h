#pragma once
#include "stdafx.h"

class Character;
class LevelBase;

class Weapon
{
public:
	Weapon(const int ammo, const float fire_speed);
	void fire(LevelBase* level, Character* character);
	virtual void handle_fire(LevelBase* level, Character* character) = 0;
	virtual void update(const float delta_time);
	int get_ammo() const;
private:
	int ammo_;
	bool can_fire_;
	float fire_timer_;
	float fire_speed_;
};
