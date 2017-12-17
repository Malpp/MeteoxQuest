#pragma once
#include "game_object.h"
#include "enemy.h"

class LevelBase;

class Wave
{
	friend class Hud;
public:
	Wave(const unsigned nbr_enemies, const float delay);
	~Wave();
	int get_delay() const;
	int get_size() const;
	void add_enemy(Enemy* enemy);
	void spawn_enemies(LevelBase* level);
	void update(const float delta_time);
	void set_delay(int delay);
private:
	std::vector<GameObject*> objects_;
	float delay_;
	unsigned nbr_enemies_;
};

