#include "stdafx.h"
#include "player.h"

const sf::Vector2f Player::size_ = sf::Vector2f( 16 * 5, 16 * 5 );
const float Player::movespeed_ = 600;
const float Player::frame_delay_ = 0.2f;

Player::Player(const sf::Vector2f& pos, float angle, sf::Texture* texture)
	: Character( pos, angle, texture, size_, no_frames_, RIGHT, frame_delay_, movespeed_ )
{
}

void Player::up()
{
	state_ = UP;
	Character::up();
}

void Player::down()
{
	state_ = DOWN;
	Character::down();
}

void Player::left()
{
	state_ = LEFT;
	Character::left();
}

void Player::right()
{
	state_ = LEFT;
	Character::right();
}
