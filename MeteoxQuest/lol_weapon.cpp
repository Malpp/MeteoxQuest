#include "stdafx.h"
#include "lol_weapon.h"
#include "lol_projectile.h"
#include "level_base.h"
#include "character.h"

const float LOLWeapon::fire_speed_ = 0.5f;

LOLWeapon::LOLWeapon(const GameObject::Color color)
	: Weapon(ammo_, fire_speed_, color)
{
}

void LOLWeapon::handle_fire(LevelBase* level, Character* character)
{
	level->add_game_object(new LOLProjectile(character->getPosition(),
		0,
		sf::Vector2f(-1, 0),
		color_));
}
