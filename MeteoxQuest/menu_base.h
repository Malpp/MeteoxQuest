#pragma once
#include "stdafx.h"
#include "scene.h"
#include "menu_manager.h"

class MenuBase : public Scene
{
public:
	MenuBase(sf::RenderWindow* window, Scene::Scenes scene_to_exit);
	void input() override;
	void draw() override;
	virtual void update(float delta_time) override;
protected:
	MenuManager menu_manager_;
	std::string error_string_;
private:
	Scenes exit_scene_;
	sf::Sprite background_sprite_;
};
