#pragma once
#include "stdafx.h"
#include "character.h"

class Player : public Character
{
public:
	Player( const sf::Vector2f& pos, float angle, sf::Texture* texture );

	void up() override;
	void down() override;
	void left() override;
	void right() override;
private:
	static const sf::Vector2f size_;
	static const int no_frames_ = 2;
	static const int no_states_ = 4;
	static const float movespeed_;
	static const float frame_delay_;
};
