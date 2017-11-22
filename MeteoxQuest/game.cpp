#include "stdafx.h"
#include "Game.h"
#include "scene.h"
#include "level1.h"

ResourceHandler Game::resource_handler_;

Game::Game()
{
	//Init window and view
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Meteox Quest", sf::Style::Close);
	view.setSize(CAMARA_WIDTH, CAMERA_HEIGHT);
	view.setCenter(GAME_WIDTH * 0.5f, GAME_HEIGHT * 0.5f);
	window->setView(view);
	srand(time(nullptr));
	rand();


	running = true;
	current_scene_ = Scene::GAME;
}

Game::~Game()
{
	delete window;
}

void Game::run()
{
	while (running)
	{
		std::cout << current_scene_ << "\n";
		switch (current_scene_)
		{
		case Scene::EXIT:
			running = false;
			break;
		case Scene::GAME:
			active_scene_ = new Level1(window);
			current_scene_ = active_scene_->run();
			break;
		}

		delete active_scene_;
		active_scene_ = nullptr;

	}
}
