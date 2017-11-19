#include "stdafx.h"
#include "level_base.h"

LevelBase::LevelBase(sf::RenderWindow* window)
	: Scene(window)
{
}

void LevelBase::input()
{
	while (window_->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				change_scene(EXIT);
				break;
			default:
				break;
			}
		}
		manage_input(event);
	}
}

void LevelBase::manage_input(sf::Event event)
{
}
