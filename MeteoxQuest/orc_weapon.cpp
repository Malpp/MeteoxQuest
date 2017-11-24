#include "stdafx.h"
#include "orc_weapon.h"

const float OrcWeapon::fire_speed_ = 1;

OrcWeapon::OrcWeapon()
	: Weapon(ammo_, fire_speed_)
{

}

void OrcWeapon::handle_fire( LevelBase* level, Character* character )
{
	//level->add_game_object( new GCProjectile( character->getPosition(), 0, sf::Vector2f( -1, 0 ) ) );
}
