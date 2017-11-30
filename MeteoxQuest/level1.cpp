#include "stdafx.h"
#include "level1.h"
#include "GC_enemy.h"
#include "orc_enemy.h"
#include "ken_enemy.h"
#include "lol_enemy.h"
#include "cloud9_enemy.h"
#include "Game.h"
#include "deque.h"
#include <deque>

sf::Texture* Level1::texture_ = Game::resource_handler_.add_texture(
	"level1.png");

Level1::Level1(sf::RenderWindow* window)
	: LevelBase(window, texture_, 300)
{
	load_level("Assets//level1.json");
	add_game_object(new Cloud9Enemy(sf::Vector2f(1300, 0), 0, GameObject::generate_random_color()));
}

void Level1::update(const float delta_time)
{
	LevelBase::update(delta_time);
}
