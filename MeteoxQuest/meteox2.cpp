#include "stdafx.h"
#include "meteox2.h"

const float Meteox2::move_speed_ = 350;
const sf::Vector2f Meteox2::size_ = sf::Vector2f(684 * 0.5f, 767 * 0.5f);
sf::Texture* Meteox2::texture;

Meteox2::Meteox2(
	const sf::Vector2f& pos,
	const float angle)
	: Boss(pos, angle, texture, size_, move_speed_, base_life_)
{
}