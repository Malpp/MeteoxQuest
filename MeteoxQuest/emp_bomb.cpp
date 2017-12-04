#include "stdafx.h"
#include "emp_bomb.h"
#include "Game.h"
#include "helper.h"
#include "level_base.h"

const sf::Vector2f EmpBomb::size_ = sf::Vector2f(30, 30);
sf::Texture* EmpBomb::texture_;
const float EmpBomb::movespeed_ = 100;
const float EmpBomb::frame_delay_ = 0.2f;

EmpBomb::EmpBomb(const sf::Vector2f& pos,
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
