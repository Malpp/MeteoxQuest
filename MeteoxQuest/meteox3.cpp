#include "stdafx.h"
#include "meteox3.h"

const float Meteox3::move_speed_ = 400;
const sf::Vector2f Meteox3::size_ = sf::Vector2f(314, 400);
sf::Texture* Meteox3::texture;

Meteox3::Meteox3(
	const sf::Vector2f& pos,
	const float angle)
	: Boss(pos, angle, texture, size_, move_speed_, base_life_)
{
}