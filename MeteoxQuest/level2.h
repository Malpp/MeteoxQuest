#pragma once
#include "stdafx.h"
#include "level_base.h"

class Level2 : public LevelBase
{
public:
	Level2(sf::RenderWindow* window);
	void update(float delta_time) override;
	static sf::Texture* texture_;
};
