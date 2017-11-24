#pragma once
#include "stdafx.h"
#include "weapon.h"

class HeartWeapon : public Weapon
{
public:
	HeartWeapon();
	void handle_fire(LevelBase* level, Character* character) override;
private:
	static const int ammo_ = -1;
	static const float fire_speed_;
};
