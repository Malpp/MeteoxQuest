#pragma once
#include "game_object.h"

class Player;

class Shield : public GameObject
{
public:
	Shield(Player* player);
	void update(const float delta_time);
	static sf::Texture* shield_texture;
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
	void on_death(LevelBase* level) override;
private:
	static const sf::Vector2f size_;
	static const int no_frames_ = 10;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
	static const int base_life_ = 3;
	static const int base_damage_ = 0;
	Player* player_;
};
