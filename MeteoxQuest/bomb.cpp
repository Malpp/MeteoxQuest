﻿#include "stdafx.h"
#include "bomb.h"
#include "helper.h"
#include "level_base.h"

const float Bomb::orbit_speed_ = 100;
const float Bomb::max_orbit_distance_ = 110;
const float Bomb::orbit_correction_speed_ = 40;

Bomb::Bomb(
	const sf::Vector2f& pos,
	const float angle,
	sf::Texture* texture,
	const sf::Vector2f& size,
	const int no_frames,
	const int no_states,
	const float frame_delay,
	const float movespeed)
	: PowerUp(pos,
	          angle,
	          texture,
	          size,
	          no_frames,
	          no_states,
	          frame_delay,
	          movespeed)
	, state_(SEEKING)
	, orbit_center_(nullptr)
	, orbit_counter_(0)
{
}

bool Bomb::launch(GameObject* other)
{
	if(state_ == ORBIT && !(orbit_distance_ < max_orbit_distance_))
	{
		state_ = LAUNCH;
		direction_ = Helper::movePointByAngle(10,
		                                      Helper::angleBetweenTwoPoints(
			                                      getPosition(),
			                                      other->getPosition()) + 270);
		type_ = PLAYER;
		return true;
	}
	return false;
}

void Bomb::update(const float delta_time, LevelBase* level)
{
	switch(state_)
	{
		case SEEKING:
			direction_ = Helper::movePointByAngle(1,
			                                      Helper::angleBetweenTwoPoints(
				                                      getPosition(),
				                                      level->get_player()->
				                                             getPosition()));
			break;
		case ORBIT:
			if(orbit_distance_ < max_orbit_distance_)
			{
				orbit_distance_ += orbit_correction_speed_ * delta_time;
				setPosition(orbit_center_->getPosition() + Helper::
					movePointByAngle(orbit_distance_,
					                 orbit_counter_));
			}
			else
			{
				setPosition(orbit_center_->getPosition() + Helper::
					movePointByAngle(max_orbit_distance_,
					                 orbit_counter_));
				orbit_counter_ += orbit_speed_ * delta_time;
			}
			break;
	}

	if(state_ == LAUNCH)
		NonCharacter::update(delta_time, level);
	else
		PowerUp::update(delta_time, level);
}

void Bomb::handle_collision(GameObject* other, LevelBase* level)
{
	if(dynamic_cast<Player*>(other))
	{
		if(state_ == SEEKING)
		{
			orbit_center_ = other;
			state_ = ORBIT;
			orbit_counter_ = Helper::angleBetweenTwoPoints(other->getPosition(),
			                                               getPosition());
			orbit_distance_ = Helper::distanceBetweenTwoPoints(getPosition(),
			                                                   other->
			                                                   getPosition());
		}
	}

	if(dynamic_cast<Enemy*>(other))
	{
		take_damage(other, level);
		//despawn();
	}
}

void Bomb::handle_edge()
{
	if(state_ != ORBIT)
		PowerUp::handle_edge();
}
