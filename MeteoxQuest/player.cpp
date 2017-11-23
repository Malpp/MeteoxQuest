#include "stdafx.h"
#include "player.h"
#include "heart_projectile.h"
#include "level_base.h"

const sf::Vector2f Player::size_ = sf::Vector2f( 140, 80 );
const float Player::movespeed_ = 600;
const float Player::frame_delay_ = 0.1f;
const float Player::fire_speed_ = 0.25f;

Player::Player(const sf::Vector2f& pos, float angle, sf::Texture* texture)
	: Character( pos, angle, texture, size_, no_frames_, COUNT, frame_delay_, movespeed_, fire_speed_ )
{
}

void Player::update(const float delta_time, LevelBase* level)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		up();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		left();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		down();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		right();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		fire(level);

	Character::update( delta_time, level);
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
	state_ = RIGHT;
	Character::right();
}

void Player::handle_fire(LevelBase* level)
{
	level->add_game_object(new HeartProjectile(getPosition(), 0, sf::Vector2f(1, 0)));
}
