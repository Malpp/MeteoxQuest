#pragma once
#include "stdafx.h"
#include "level_base.h"

class Level3 : public LevelBase
{
public:
	Level3(sf::RenderWindow* window);
	void update(float delta_time) override;
	static sf::Texture* texture_;
};
