#pragma once
#include "boss.h"

class Meteox3 : public Boss
{
public:
	Meteox3(
		const sf::Vector2f& pos,
		float angle);
	static sf::Texture* texture;
private:
	static const int base_life_ = 70;
	static const float move_speed_;
	static const sf::Vector2f size_;
};
