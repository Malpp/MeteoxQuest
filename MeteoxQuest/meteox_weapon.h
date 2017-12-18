#pragma once
#include "game_object.h"
#include "weapon.h"

class Character;
class LevelBase;

class MeteoxWeapon : public Weapon
{
public:
	MeteoxWeapon(const GameObject::Color color);
	void handle_fire(LevelBase* level, Character* character) override;
private:
	static const int ammo_ = -1;
	static const float fire_speed_;
};

