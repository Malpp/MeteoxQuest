#include "stdafx.h"
#include "level1.h"

Level1::Level1(sf::RenderWindow* window)
	: LevelBase(window)
{
}

void Level1::update(float delta_time)
{
}

void Level1::draw()
{
	window_->clear();
	window_->display();
}
