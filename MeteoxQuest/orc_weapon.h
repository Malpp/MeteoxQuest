#pragma once
#include "weapon.h"

class OrcWeapon : public Weapon
{
public:
	OrcWeapon(const GameObject::Color color);
	void handle_fire(LevelBase* level, Character* character) override;
private:
	static const int ammo_ = -1;
	static const float fire_speed_;
};
