#pragma once
#include "stdafx.h"
#include "resourcehandler.h"

/// <summary>
/// The abstract scene
/// </summary>

class Scene
{
public:
	//Scene types
	enum Scenes
	{
		EXIT,
		SPLASH,
		LEVEL1,
		LEVEL2,
		LEVEL3,
		LEVEL4,
		MENU,
		LOADING,
		END
	};

	Scene(sf::RenderWindow* window);

	virtual ~Scene()
	{
	} //Pour que le destructeur de l'objet en mémoire soit apellé
	virtual Scenes run();

	//La boucle de jeu est maintenant gérée par la scène
	virtual void input() = 0;
	virtual void update(float delta_time) = 0;
	virtual void draw() = 0;

protected:

	void close();
	void change_scene(Scenes scene);

	sf::RenderWindow* window_;
	sf::Event event;

	Scenes returned_scene_;
	ResourceHandler resource_handler_;
	bool isRunning;
	sf::Clock clock;
};
