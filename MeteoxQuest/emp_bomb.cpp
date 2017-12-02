#include "stdafx.h"
#include "emp_bomb.h"
#include "Game.h"
#include "helper.h"
#include "level_base.h"

const sf::Vector2f EmpBomb::size_ = sf::Vector2f( 30, 30 );
sf::Texture* EmpBomb::texture_ = Game::resource_handler_.add_texture("emp_bomb.png");
const float EmpBomb::movespeed_ = 100;
const float EmpBomb::frame_delay_ = 0.2f;

EmpBomb::EmpBomb(const sf::Vector2f& pos,
	const float angle)
	: PowerUp( pos,
		angle,
		texture_,
		size_,
		no_frames_,
		no_states_,
		frame_delay_ )
{
}

void EmpBomb::update(const float delta_time, LevelBase* level)
{
	direction_ = Helper::movePointByAngle(1, Helper::angleBetweenTwoPoints( getPosition(), level->get_player()->getPosition() )) * movespeed_;
	PowerUp::update( delta_time, level );
}
