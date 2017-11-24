#include "stdafx.h"
#include "level_base.h"
#include "character.h"
#include "ken_weapon.h"
#include "ken_projectile.h"

const float KenWeapon::fire_speed_ = 3;

KenWeapon::KenWeapon()
	: Weapon( ammo_, fire_speed_ )
{}

void KenWeapon::handle_fire( LevelBase* level, Character* character )
{
	level->add_game_object( new KenProjectile( character->getPosition(), 0, sf::Vector2f( -1, 0 ) ) );
}
