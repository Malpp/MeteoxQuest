#pragma once
#include "stdafx.h"
#include "scene.h"
#include "player.h"
#include "wave.h"
#include <queue>

class GameObject;

class LevelBase : public Scene
{
public:
	LevelBase(
		sf::RenderWindow* window,
		sf::Texture* texture,
		float scroll_speed);
	virtual ~LevelBase();
	void input() override;
	void update(float delta_time) override;
	void draw() override;
	virtual void manage_input(sf::Event event);
	void add_game_object(GameObject* projectile);

private:
	Player* player_;
	float scroll_speed_;
	sf::Sprite background_sprites_[2];
	std::vector<GameObject*> objects_;
	float fps_timer_;
	int fps_;
	std::queue<Wave*> waves_;
protected:
	bool load_level(const std::string path);
	sf::Vector2f background_size_;

};
