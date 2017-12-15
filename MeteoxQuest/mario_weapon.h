#pragma once
#include "stdafx.h"
#include "weapon.h"

class MarioWeapon : public Weapon
{
public:
	MarioWeapon();
	void handle_fire( LevelBase* level, Character* character ) override;
private:
	static const int ammo_ = 10;
	static const float fire_speed_;
};
