#pragma once
#include "boss.h"

class Meteox1 : public Boss
{
public:
	Meteox1(
		const sf::Vector2f& pos,
		float angle);
	static sf::Texture* texture;
private:
	static const int base_life_ = 50;
	static const float move_speed_;
	static const sf::Vector2f size_;
};
