#pragma once
#include "player_projectile.h"

class MarioProjectile : public PlayerProjectile
{
public:
	enum MarioNote{
		Mario,
		Mushrooom,
		Yoshi,
		Star,
		Flower,
		Gameboy,
		Dog,
		Cat,
		Pig,
		Goose,
		Face,
		Plane,
		Boat,
		Car,
		Heart,
		Count
	};
	MarioProjectile(const sf::Vector2f& pos,
					float angle,
					const sf::Vector2f& direction);
	static sf::Texture* texture_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 1;
	static const int no_states_ = Count;
	static const float movespeed_;
	static const float frame_delay_;
};
