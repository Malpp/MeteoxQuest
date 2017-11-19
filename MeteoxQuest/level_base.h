#pragma once
#include "stdafx.h"
#include "scene.h"

class LevelBase : public Scene
{
public:
	LevelBase(sf::RenderWindow* window);
	void input() override;
	virtual void manage_input(sf::Event event);
};
