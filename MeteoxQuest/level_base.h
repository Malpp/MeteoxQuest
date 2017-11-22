#pragma once
#include "stdafx.h"
#include "scene.h"
#include "player.h"

class LevelBase : public Scene
{
public:
	LevelBase(sf::RenderWindow* window, const std::string& background_texture , float scroll_speed);
	virtual ~LevelBase();
	void input() override;
	void update(float delta_time) override;
	void draw() override;
	virtual void manage_input(sf::Event event);
	void add_game_object( GameObject* projectile );
private:
	Player player_;
	float scroll_speed_;
	sf::Sprite background_sprites_[2];
	std::vector<GameObject*> objects_;
};
