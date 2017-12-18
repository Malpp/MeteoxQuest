#include "stdafx.h"
#include "shield_powerup.h"
#include "player.h"

sf::Texture* ShieldPowerup::texture_;
const sf::Vector2f ShieldPowerup::size_ = sf::Vector2f(30, 30);
const float ShieldPowerup::movespeed_ = 100;
const float ShieldPowerup::frame_delay_ = 0.2f;

ShieldPowerup::ShieldPowerup(
	const sf::Vector2f& pos,
	const float angle)
	: PowerUp(
		pos,
		angle,
		texture_,
		size_,
		no_frames_,
		no_states_,
		frame_delay_,
		movespeed_)
{
}

void ShieldPowerup::handle_collision(GameObject* other, LevelBase* level)
{
	if(auto player = dynamic_cast<Player*>(other))
	{
		player->add_shield_powerup();
		despawn();
	}
}
