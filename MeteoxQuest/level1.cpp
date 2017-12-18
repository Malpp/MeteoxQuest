#include "stdafx.h"
#include "level1.h"
#include "Game.h"

sf::Texture* Level1::texture_ = Game::resource_handler_.add_texture(
	"Levels/Background/level1.png");

Level1::Level1(sf::RenderWindow* window)
	: LevelBase(window, texture_, 300)
{
	load_level("Assets/Levels/Data/level1.json");
}

void Level1::update(const float delta_time)
{
	LevelBase::update(delta_time);
}
