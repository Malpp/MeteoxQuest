#pragma once
#include "enemy.h"

class Cloud9Enemy : public Enemy
{
public:
	Cloud9Enemy(const sf::Vector2f& pos, const float angle, const Color color);
	void update(const float delta_time, LevelBase* level) override;
private:
	static sf::Texture* textures_[3];
	static const std::string texture_name_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 1;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
	static const int base_life_ = 10;
};

