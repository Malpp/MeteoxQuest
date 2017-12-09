#include "stdafx.h"
#include "weapon.h"

Weapon::Weapon(
	const int ammo,
	const float fire_speed,
	const GameObject::Color color)
{
	can_fire_ = true;
	fire_timer_ = 0;
	ammo_ = ammo;
	fire_speed_ = fire_speed;
	color_ = color;
}

void Weapon::fire(LevelBase* level, Character* character)
{
	if(can_fire_ && ammo_ != 0)
	{
		if(ammo_ > 0)
			--ammo_;
		can_fire_ = false;
		handle_fire(level, character);
	}
}

void Weapon::update(const float delta_time)
{
	if(!can_fire_)
	{
		fire_timer_ += delta_time;
		if(fire_timer_ > fire_speed_)
		{
			can_fire_ = true;
			fire_timer_ = 0;
		}
	}
}

int Weapon::get_ammo() const
{
	if(ammo_ < 0)
		return -1;
	return ammo_;
}

bool Weapon::can_fire() const
{
	return can_fire_;
}

void Weapon::jam_weapon()
{
	fire_timer_ = 0;
	can_fire_ = false;
}
