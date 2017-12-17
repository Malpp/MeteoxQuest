#pragma once
#include "stdafx.h"
#include "level_base.h"

class Level4 : public LevelBase
{
public:
	Level4(sf::RenderWindow* window);
	void update(float delta_time) override;
	static sf::Texture* texture_;
};
