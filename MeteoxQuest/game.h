#pragma once
#include "stdafx.h"
#include "resourcehandler.h"
#include "scene.h"
#include <cstdbool>

class Game
{
public:
	//Add new vars here

private:
	//Add new vars here
	bool running;
	Scene::Scenes current_scene_;
	Scene* active_scene_;
	Scene::Scenes last_scene_;
	static bool player_is_alive_;
	static int player_life_;
	static int score_;
	//
	//TEMPLATE STUFF BELOW
	//

public:
	//Template variables
	Game();
	~Game();
	void run();
	static int get_player_life();
	static bool get_player_alive();
	static void set_player_alive(bool player_is_alive);
	static int get_score();
	static void increase_score(int points);
	static void player_damage(int damage);
	static void reset();
	/// <summary>
	/// The Game width
	/// </summary>
	static const int GAME_WIDTH = 1920;
	/// <summary>
	/// The Game height
	/// </summary>
	static const int GAME_HEIGHT = 1080;
	/// <summary>
	/// The camara width
	/// </summary>
	static const int CAMARA_WIDTH = 1920;
	/// <summary>
	/// The camera height
	/// </summary>
	static const int CAMERA_HEIGHT = 1080;
	/// <summary>
	/// The window width
	/// </summary>
	static const int WINDOW_WIDTH = 1280;
	/// <summary>
	/// The window height
	/// </summary>
	static const int WINDOW_HEIGHT = 720;

	static ResourceHandler resource_handler_;

	static sf::Font font;

private:
	//Template variables
	/// <summary>
	/// The window
	/// </summary>
	sf::RenderWindow* window;

	/// <summary>
	/// The view
	/// Uses the CAMERA_WIDTH and HEIGHT variables
	/// </summary>
	sf::View view;
};
