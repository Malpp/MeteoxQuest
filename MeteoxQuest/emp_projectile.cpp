#include "stdafx.h"
#include "emp_projectile.h"
#include "Game.h"
#include "movement_effector.h"
#include "weapon_effector.h"

sf::Texture* EmpBlast::texture_;
const sf::Vector2f EmpBlast::size_ = sf::Vector2f( 690, 690 );
const float EmpBlast::movespeed_ = 0;
const float EmpBlast::frame_delay_ = 0.08f;

EmpBlast::EmpBlast(const sf::Vector2f& pos,
					const float angle)
	: PlayerProjectile(pos,
						angle,
						texture_,
						size_,
						no_frames_,
						no_states_,
						frame_delay_,
						sf::Vector2f(),
						movespeed_,
					   damage_)
{
}

void EmpBlast::update(const float delta_time, LevelBase* level)
{
	if(frame_ >= max_frame_)
	{
		despawn();
	}
	PlayerProjectile::update( delta_time, level );
}

void EmpBlast::on_death(LevelBase* level)
{
}

void EmpBlast::handle_collision(GameObject* other, LevelBase* level)
{
	if(std::find(effected_objects_.begin(), effected_objects_.end(), other) == effected_objects_.end())
	{
		other->add_effector(new MovementEffector);
		other->add_effector(new WeaponEffector);
		effected_objects_.push_back(other);
	}
}
