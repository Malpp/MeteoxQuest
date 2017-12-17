#include "stdafx.h"
#include "heart_weapon.h"
#include "heart_projectile.h"
#include "level_base.h"
#include "character.h"

const float HeartWeapon::fire_speed_ = 0.25f;
sf::SoundBuffer HeartWeapon::fire_sound;

HeartWeapon::HeartWeapon()
	: Weapon(ammo_, fire_speed_, GameObject::NONE)
{
}

void HeartWeapon::handle_fire(LevelBase* level, Character* character)
{
	level->add_game_object(
		new HeartProjectile(character->getPosition(), 0, sf::Vector2f(1, 0)));
	level->play_sound(&fire_sound);
}
