#include "stdafx.h"
#include "Game.h"

ResourceHandler Game::resource_handler_;

void Game::input()
{
	while (window->pollEvent( event ))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				window->close();
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
		break;
	}
}

void Game::update()
{
	float timeElapsed = clock.restart().asSeconds();

	//Fps counter
	frame_time_ += timeElapsed;
	if (frame_time_ > 1)
	{
		std::cout << "FPS: " << frame_counter_ << "\n";
		frame_time_ = 0;
		frame_counter_ = 0;
	}
	frame_counter_++;

	//Add new stuff below this
}


void Game::draw()
{
	window->clear();

	//Draw code

	window->display();
}

Game::Game()
{
	//Init window and view
	window = new sf::RenderWindow( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "SFML", sf::Style::Close );
	view.setSize( CAMARA_WIDTH, CAMERA_HEIGHT );
	view.setCenter( GAME_WIDTH * 0.5f, GAME_HEIGHT * 0.5f );
	window->setView( view );
	clock.restart();
	srand( time( nullptr ) );
	rand();

	resource_handler_.add_texture( "ben.png" );
}

Game::~Game()
{
	delete window;
}

void Game::run()
{
	window->setActive( false );

	while (window->isOpen())
	{
		input();
		update();
		draw();
	}
}
