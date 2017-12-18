#include "stdafx.h"
#include "meteox4.h"

const float Meteox4::move_speed_ = 400;
const sf::Vector2f Meteox4::size_ = sf::Vector2f(311, 345);
sf::Texture* Meteox4::texture;

Meteox4::Meteox4(
	const sf::Vector2f& pos,
	const float angle)
	: Boss(pos, angle, texture, size_, move_speed_, base_life_)
{
}