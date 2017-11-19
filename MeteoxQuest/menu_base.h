#pragma once
#include "stdafx.h"
#include "scene.h"
#include "menu_manager.h"


	class MenuBase : public Scene
	{
	public:
		MenuBase(sf::RenderWindow* window, Scene::Scenes scene_to_exit );
		void input() override;
		void draw() override;
	protected:
		MenuManager menu_manager_;
		std::string error_string_;
	private:
		Scenes exit_scene_;
	};
