#include "stdafx.h"
#include "powerup.h"
#include "helper.h"
#include "level_base.h"

PowerUp::PowerUp(const sf::Vector2f& pos,
				const float angle,
				sf::Texture* texture,
				const sf::Vector2f& size,
				const int no_frames,
				const int no_states,
				const float frame_delay,
				const float movespeed)
	: NonCharacter(pos,
					angle,
					texture,
					size,
					no_frames,
					no_states,
					frame_delay,
					powerup_life_,
					NONE,
					powerup_damage_,
					ENEMY,
					movespeed)
{
}

void PowerUp::update(const float delta_time, LevelBase* level)
{
	direction_ = Helper::movePointByAngle(1,
										  Helper::angleBetweenTwoPoints(
										  getPosition(),
										  level->get_player()->
										  getPosition()));
	NonCharacter::update(delta_time, level);
}

void PowerUp::on_death(LevelBase* level)
{
}
