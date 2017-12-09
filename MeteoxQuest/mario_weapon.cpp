#include "stdafx.h"
#include "level_base.h"
#include "character.h"
#include "mario_weapon.h"
#include "mario_projectile.h"
#include "helper.h"

const float MarioWeapon::fire_speed_ = 0.5f;

MarioWeapon::MarioWeapon()
	: Weapon( ammo_, fire_speed_, GameObject::NONE )
{}

void MarioWeapon::handle_fire( LevelBase* level, Character* character )
{
	level->add_game_object(
		new MarioProjectile( character->getPosition(), 0, Helper::movePointByAngle(1, 30)) );
	level->add_game_object(
		new MarioProjectile( character->getPosition(), 0, Helper::movePointByAngle( 1, 0 ) ) );
	level->add_game_object(
		new MarioProjectile( character->getPosition(), 0, Helper::movePointByAngle( 1, -30 ) ) );
}
