#include "stdafx.h"
#include "orc_weapon.h"
#include "orc_projectile.h"
#include "level_base.h"

const float OrcWeapon::fire_speed_ = 0.8f;

OrcWeapon::OrcWeapon(const GameObject::Color color)
	: Weapon(ammo_, fire_speed_, color)
{
}

void OrcWeapon::handle_fire(LevelBase* level, Character* character)
{
	level->add_game_object(new OrcProjectile(character->getPosition(),
	                                         0,
	                                         sf::Vector2f(-1, 0),
	                                         color_));
}
