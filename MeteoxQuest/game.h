#pragma once
#include "stdafx.h"
#include "resourcehandler.h"

class Game
{

public:
	//Add new vars here

private:
	//Add new vars here

//
//TEMPLATE STUFF BELOW
//

public:
	//Template variables
	Game();
	~Game();
	void run();	
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

private:
	//Template variables	
	/// <summary>
	/// The window
	/// </summary>
	sf::RenderWindow* window;	
	/// <summary>
	/// The event
	/// </summary>
	sf::Event event;	
	/// <summary>
	/// The clock
	/// Used to time the frames
	/// </summary>
	sf::Clock clock;	
	/// <summary>
	/// The view
	/// Uses the CAMERA_WIDTH and HEIGHT variables
	/// </summary>
	sf::View view;	
	/// <summary>
	/// Inputs.
	/// </summary>
	void input();	
	/// <summary>
	/// Updates the game.
	/// </summary>
	void update();	
	/// <summary>
	/// Draws the game.
	/// </summary>
	void draw();	
	/// <summary>
	/// The frame time
	/// </summary>
	float frame_time_ = 0;	
	/// <summary>
	/// The frame counter
	/// </summary>
	int frame_counter_ = 0;
};
