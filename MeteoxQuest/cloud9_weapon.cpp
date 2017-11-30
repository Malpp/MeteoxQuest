#include "stdafx.h"
#include "cloud9_weapon.h"
#include "level_base.h"
#include "lol_enemy.h"

const float Cloud9Weapon::fire_speed_ = 5;

Cloud9Weapon::Cloud9Weapon(const GameObject::Color color)
	:Weapon( ammo_, fire_speed_, color)
{
}

void Cloud9Weapon::handle_fire(LevelBase* level, Character* character)
{
	level->add_game_object(new LOLEnemy(character->getPosition(),
		0,
		color_));
}
