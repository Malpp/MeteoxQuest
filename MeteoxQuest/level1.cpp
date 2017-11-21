#include "stdafx.h"
#include "level1.h"

Level1::Level1(sf::RenderWindow* window)
	: LevelBase(window, "background.jpg", 300)
{
}

void Level1::update(float delta_time)
{
	LevelBase::update( delta_time );
}


