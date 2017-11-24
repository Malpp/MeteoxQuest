#include "stdafx.h"
#include "player.h"
#include "level_base.h"
#include "Game.h"
#include "heart_weapon.h"

sf::Texture* Player::texture_ = Game::resource_handler_.add_texture("player.png");
const sf::Vector2f Player::size_ = sf::Vector2f( 140, 80 );
const float Player::movespeed_ = 600;
const float Player::frame_delay_ = 0.1f;

Player::Player(const sf::Vector2f& pos, const float angle)
	: Character( pos, angle, texture_, size_, no_frames_, COUNT, frame_delay_, movespeed_ )
{
	weapon_ = new HeartWeapon;
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

	if (velocity_.x == 0 && velocity_.y == 0)
		state_ = IDLE;

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
