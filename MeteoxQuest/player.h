#pragma once
#include "stdafx.h"
#include "character.h"

class LevelBase;

class Player : public Character
{
public:
	Player( const sf::Vector2f& pos, float angle, sf::Texture* texture );

	void update(const float delta_time, LevelBase* level) override;
	void up() override;
	void down() override;
	void left() override;
	void right() override;
	void handle_fire(LevelBase* level) override;
private:
	static const sf::Vector2f size_;
	static const int no_frames_ = 4;
	static const float movespeed_;
	static const float frame_delay_;
	static const float fire_speed_;
};
