#include "stdafx.h"
#include "wave.h"
#include "level_base.h"

Wave::Wave(const unsigned nbr_enemies, const float delay)
{
	nbr_enemies_ = nbr_enemies;
	delay_ = delay;
}


Wave::~Wave()
{
	for (GameObject* game_object : objects_)
	{
		delete game_object;
	}
}

void Wave::add_enemy(Enemy* enemy)
{
	objects_.push_back(enemy);
}

int Wave::get_delay() const
{
	return delay_;
}

int Wave::get_size() const
{
	return nbr_enemies_;
}

void Wave::spawn_enemies(LevelBase* level)
{
	for (GameObject* object : objects_)
	{
		level->add_game_object(object);
	}

	objects_.clear();
}

void Wave::update(const float delta_time)
{
	delay_ -= delta_time;
}
