#pragma once
#include "stdafx.h"
#include "scene.h"
#include "player.h"

class LevelBase : public Scene
{
public:
	LevelBase(sf::RenderWindow* window, const std::string& background_texture , float scroll_speed);
	void input() override;
	void update(float delta_time) override;
	void draw() override;
	virtual void manage_input(sf::Event event);
private:
	Player player_;
	float scroll_speed_;
	sf::Sprite background_sprites_[2];

};
