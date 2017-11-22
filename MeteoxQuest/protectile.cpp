#include "stdafx.h"
#include "projectile.h"
#include "Game.h"

Projectile::Projectile(const sf::Vector2f& pos, float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay, const sf::Vector2f& direction )
	: GameObject( pos, angle, texture, size, no_frames, no_states, frame_delay )
{
	direction_ = direction;
}

void Projectile::update(const float delta_time)
{
	velocity_ = direction_;
	GameObject::update( delta_time );
}

bool Projectile::is_at_edge()
{
	const sf::Vector2f current_pos = getPosition();
	if (current_pos.x > Game::GAME_WIDTH + half_texture_size_.x ||
		current_pos.x < -half_texture_size_.x ||
		current_pos.y > Game::GAME_HEIGHT + half_texture_size_.y ||
		current_pos.y < -half_texture_size_.y)
		return true;

	return false;
}

void Projectile::handle_edge()
{
	despawn();
}
