#include "stdafx.h"
#include "character.h"

Character::Character(
	const sf::Vector2f& pos,
	const float angle,
	sf::Texture* texture,
	const sf::Vector2f& size,
	const int no_frames,
	const int no_states,
	const float frame_delay,
	const float move_speed,
	const int life,
	Color color)
	: GameObject(pos,
	             angle,
	             texture,
	             size,
	             no_frames,
	             no_states,
	             frame_delay,
	             life,
	             color)
{
	movespeed_ = move_speed;
	weapon_ = nullptr;
}

Character::~Character()
{
	delete weapon_;
}

void Character::update(const float delta_time, LevelBase* level)
{
	weapon_->update(delta_time);

	if(velocity_.x != 0 && velocity_.y != 0)
	{
		velocity_.x *= 0.7071;
		velocity_.y *= 0.7071;
	}

	GameObject::update(delta_time, level);
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

void Character::fire(LevelBase* level)
{
	weapon_->fire(level, this);
}
