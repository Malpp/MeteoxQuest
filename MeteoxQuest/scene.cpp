#include "stdafx.h"
#include "scene.h"

Scene::Scene(sf::RenderWindow* window)
{
	isRunning = true;
	window_ = window;
	returned_scene_ = EXIT;
}

Scene::Scenes Scene::run()
{
	while(isRunning)
	{
		input();
		const float delta_time = std::min(0.025f, clock.restart().asSeconds());
		update(delta_time);
		draw();
	}
	return returned_scene_;
}

void Scene::close()
{
	change_scene(EXIT);
}

void Scene::change_scene(const Scenes scene)
{
	returned_scene_ = scene;
	isRunning = false;
}
