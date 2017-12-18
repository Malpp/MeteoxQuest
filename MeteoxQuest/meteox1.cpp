#include "stdafx.h"
#include "meteox1.h"

const float Meteox1::move_speed_ = 300;
const sf::Vector2f Meteox1::size_ = sf::Vector2f(211,303);
sf::Texture* Meteox1::texture;

Meteox1::Meteox1(
	const sf::Vector2f& pos,
	const float angle)
	: Boss(pos, angle, texture, size_, move_speed_, base_life_)
{
}
