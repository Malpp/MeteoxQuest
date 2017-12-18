#include "stdafx.h"
#include "Transition.h"
#include "Game.h"


Transition::Transition(sf::RenderWindow* window, Scenes last_scene)
	: Scene(window),
	text_("Moving to next level...", Game::font, 50)
{
	text_.setPosition(Game::CAMARA_WIDTH * 0.2f, Game::CAMERA_HEIGHT / 2);
	delay_ = 5;
	scene_to_switch_ = last_scene;
}


Transition::~Transition()
{
}

void Transition::input()
{
	
}

void Transition::switch_scene()
{
	switch (scene_to_switch_)
	{
	case LEVEL1:
		change_scene(LEVEL2);
		break;
	case LEVEL2:
		change_scene(LEVEL3);
		break;
	case LEVEL3:
		change_scene(LEVEL4);
		break;
	case LEVEL4:
		change_scene(END);
		break;
	default:
		change_scene(MENU);
		break;
	}
}

void Transition::update(float delta_time)
{
	delay_ -= delta_time;
	if (delay_ <= 0)
		switch_scene();
}

void Transition::draw()
{
	window_->draw(text_);
}


