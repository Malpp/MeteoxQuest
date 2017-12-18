#pragma once
#include "scene.h"

class EndScreen : public Scene
{
public:
	EndScreen(sf::RenderWindow* window);
	~EndScreen();
	void update(float delta_time) override;
	void draw() override;
	void input() override;
private:
	sf::Sprite death_sprite_;
	sf::Sprite victory_sprite_;
	sf::Text victory_text_;
};

