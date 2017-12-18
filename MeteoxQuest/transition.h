#pragma once
#include "scene.h"

class Transition : public Scene
{
public:
	Transition(sf::RenderWindow* window, Scenes last_scene);
	~Transition();
	void switch_scene();
	void update(float delta_time) override;
	void draw() override;
	void input() override;
private:
	sf::Text text_;
	float delay_;
	Scene::Scenes scene_to_switch_;
};

