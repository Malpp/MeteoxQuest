﻿#include "stdafx.h"
#include "level3.h"
#include "Game.h"
#include "cloud9_enemy.h"
#include "emp_bomb.h"
#include "explosive_bomb.h"

sf::Texture* Level3::texture_ = Game::resource_handler_.add_texture(
	"Levels/Background/level3.png");

Level3::Level3(sf::RenderWindow* window)
	: LevelBase(window, texture_, 300)
{
	load_level("Assets/Levels/Data/level3.json");
	//add_game_object(new EmpBomb(sf::Vector2f(500, 500), 0));
	//add_game_object(new EmpBomb(sf::Vector2f(600, 600), 0));
	//add_game_object(new ExplosiveBomb(sf::Vector2f(500, 500), 0));
}

void Level3::update(const float delta_time)
{
	// Check if we should go to the next level
	if (waves_.empty() && nbr_enemies_ == 0)
	{
		change_scene(TRANSITION);
	}
	LevelBase::update(delta_time);
}
