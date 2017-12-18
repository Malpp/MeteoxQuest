#include "stdafx.h"
#include "meteox_weapon.h"
#include "meteox_projectile.h"
#include "level_base.h"
#include "helper.h"

const float MeteoxWeapon::fire_speed_ = 0.8f;

MeteoxWeapon::MeteoxWeapon(const GameObject::Color color)
	: Weapon(ammo_, fire_speed_, color)
{
}

void MeteoxWeapon::handle_fire(LevelBase* level, Character* character)
{
	for(auto i = 0; i < 5; ++i)
	{
		level->add_game_object(new MeteoxProjectile(character->getPosition(),
		                                            0,
		                                            Helper::movePointByAngle(
			                                            1,
			                                            140 + i * 20),
		                                            static_cast<GameObject::Color
		                                            >
		                                            (Helper::generateRandInt(
			                                            GameObject::RED,
			                                            GameObject::BLUE))));
	}
}
