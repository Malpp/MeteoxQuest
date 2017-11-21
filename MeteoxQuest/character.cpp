#include "stdafx.h"
#include "character.h"

Character::Character(const sf::Vector2f& pos, float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay, float move_speed )
	: GameObject(pos, angle, texture, size, no_frames, no_states, frame_delay)
{
	movespeed_ = move_speed;
}

void Character::update(const float delta_time)
{
	if (velocity_.x != 0 && velocity_.y != 0)
	{
		velocity_.x *= 0.7071;
		velocity_.y *= 0.7071;
	}
	
	if (velocity_.x == 0 && velocity_.y == 0)
		state_ = IDLE;
	
	GameObject::update( delta_time );
}

void Character::up()
{
	velocity_.y -= movespeed_;
}

void Character::down()
{
	velocity_.y += movespeed_;
}

void Character::left()
{
	velocity_.x -= movespeed_;
}

void Character::right()
{
	velocity_.x += movespeed_;
}
