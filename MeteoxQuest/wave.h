#pragma once
#include "game_object.h"
#include "enemy.h"

class LevelBase;

class Wave
{
public:
	Wave(const size_t nbr_enemies, const float delay);
	~Wave();
	int delay();
	void add_enemy(Enemy* enemy);
	void spawn_enemies(LevelBase* level);
	void update(const float delta_time);
private:
	std::vector<GameObject*> objects_;
	float delay_;
	size_t nbr_enemies_;
};

