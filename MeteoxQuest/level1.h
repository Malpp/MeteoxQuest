#pragma once
#include "stdafx.h"
#include "level_base.h"

class Level1 : public LevelBase
{
public:
	Level1(sf::RenderWindow* window);

	void update(float delta_time) override;
};
