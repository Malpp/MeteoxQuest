#pragma once
#include "weapon.h"

class Cloud9Weapon : public Weapon
{
public:
	Cloud9Weapon(const GameObject::Color color);
	void handle_fire(LevelBase* level, Character* character) override;
private:
	static const int ammo_ = -1;
	static const float fire_speed_;
};

