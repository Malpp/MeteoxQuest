#include "stdafx.h"
#include "Game.h"
#include "scene.h"
#include "level1.h"
#include "main_menu.h"
#include "loading.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "Transition.h"
#include "end_screen.h"

ResourceHandler Game::resource_handler_;
sf::Font Game::font;
bool Game::player_is_alive_ = true;
int Game::player_life_ = 3;
int Game::score_ = 0;

Game::Game()
{
	//Init window and view
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
								"Meteox Quest",
								sf::Style::Close);
	view.setSize(CAMARA_WIDTH, CAMERA_HEIGHT);
	view.setCenter(GAME_WIDTH * 0.5f, GAME_HEIGHT * 0.5f);
	window->setView(view);
	srand(time(nullptr));
	rand();
	running = true;
	last_scene_ = Scene::LOADING;
	current_scene_ = Scene::LOADING;
}

Game::~Game()
{
	delete window;
}

void Game::run()
{
	while(running)
	{
		std::cout << current_scene_ << "\n";
		switch(current_scene_)
		{
			case Scene::EXIT:
				running = false;
				break;
			case Scene::LEVEL1:
				active_scene_ = new Level1(window);
				current_scene_ = active_scene_->run();
				last_scene_ = Scene::LEVEL1;
				break;
			case Scene::LEVEL2:
				active_scene_ = new Level2(window);
				current_scene_ = active_scene_->run();
				last_scene_ = Scene::LEVEL2;
				break;
			case Scene::LEVEL3:
				active_scene_ = new Level3(window);
				current_scene_ = active_scene_->run();
				last_scene_ = Scene::LEVEL3;
				break;
			case Scene::LEVEL4:
				active_scene_ = new Level4(window);
				current_scene_ = active_scene_->run();
				last_scene_ = Scene::LEVEL4;
				break;
			case Scene::MENU:
				active_scene_ = new MainMenu(window);
				current_scene_ = active_scene_->run();
				break;
			case Scene::LOADING:
				active_scene_ = new Loading(window);
				current_scene_ = active_scene_->run();
				break;
			case Scene::TRANSITION:
				active_scene_ = new Transition(window, last_scene_);
				current_scene_ = active_scene_->run();
				break;
			case Scene::END:
				active_scene_ = new EndScreen(window);
				current_scene_ = active_scene_->run();
				break;
		}

		delete active_scene_;
		active_scene_ = nullptr;
	}
}

int Game::get_player_life()
{
	return player_life_;
}

bool Game::get_player_alive()
{
	return player_is_alive_;
}

void Game::set_player_alive(bool player_is_alive)
{
	player_is_alive_ = player_is_alive;
}

int Game::get_score()
{
	return score_;
}

void Game::increase_score(int points)
{
	score_ += points;
}

void Game::player_damage(int damage)
{
	player_life_ -= damage;
}

void Game::reset()
{
	player_life_ = 0;
	player_is_alive_ = true;
	score_ = 0;
}