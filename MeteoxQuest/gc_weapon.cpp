#include "stdafx.h"
#include "gc_weapon.h"
#include "gc_projectile.h"
#include "level_base.h"
#include "character.h"

const float GCWeapon::fire_speed_ = 0.3f;

GCWeapon::GCWeapon(const GameObject::Color color)
	: Weapon(ammo_, fire_speed_, color)
{
}

void GCWeapon::handle_fire(LevelBase* level, Character* character)
{
	level->add_game_object(new GCProjectile(character->getPosition(),
	                                        0,
	                                        sf::Vector2f(-1, 0),
	                                        color_));
}
