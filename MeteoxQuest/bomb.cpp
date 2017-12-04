#include "stdafx.h"
#include "bomb.h"
#include "helper.h"
#include "level_base.h"

Bomb::Bomb(const sf::Vector2f& pos,
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
{
}

void Bomb::update(const float delta_time, LevelBase* level)
{
	direction_ = Helper::movePointByAngle(1,
										Helper::angleBetweenTwoPoints(getPosition(),
																	level->get_player()->getPosition()));
	PowerUp::update(delta_time, level);
}
