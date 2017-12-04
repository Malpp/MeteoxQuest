#include "stdafx.h"
#include "non_character.h"
#include "Game.h"

NonCharacter::NonCharacter(const sf::Vector2f& pos,
							const float angle,
							sf::Texture* texture,
							const sf::Vector2f& size,
							const int no_frames,
							const int no_states,
							const float frame_delay,
							const int life,
							const Color color,
							const int damage,
							const GameType type,
							const float movespeed)
	: GameObject(pos,
				angle,
				texture,
				size,
				no_frames,
				no_states,
				frame_delay,
				life,
				color,
				damage,
				type)
	, movespeed_(movespeed)
{
}

void NonCharacter::update(const float delta_time, LevelBase* level)
{
	velocity_ = direction_ *  movespeed_;
	GameObject::update(delta_time, level);
}

bool NonCharacter::is_at_edge()
{
	const sf::Vector2f current_pos = getPosition();
	if(current_pos.x > Game::GAME_WIDTH + half_texture_size_.x ||
		current_pos.x < -half_texture_size_.x ||
		current_pos.y > Game::GAME_HEIGHT + half_texture_size_.y ||
		current_pos.y < -half_texture_size_.y)
		return true;

	return false;
}

void NonCharacter::handle_edge()
{
	despawn();
}
