#include "stdafx.h"
#include "explosive_bomb.h"
#include "level_base.h"
#include "explosive_projectile.h"

const sf::Vector2f ExplosiveBomb::size_ = sf::Vector2f(30, 30);
sf::Texture* ExplosiveBomb::texture_;
const float ExplosiveBomb::movespeed_ = 100;
const float ExplosiveBomb::frame_delay_ = 0.2f;

ExplosiveBomb::ExplosiveBomb(const sf::Vector2f& pos,
							const float angle)
	: Bomb(pos,
			angle,
			texture_,
			size_,
			no_frames_,
			no_states_,
			frame_delay_,
			movespeed_)
{
}

void ExplosiveBomb::on_death(LevelBase* level)
{
	level->add_game_object(new ExplosiveBlast(getPosition(), 0));
	despawn();
}
