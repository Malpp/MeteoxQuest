#include "stdafx.h"
#include "enemy.h"
#include "Game.h"

Enemy::Enemy(const sf::Vector2f& pos, const float angle, sf::Texture* texture, const sf::Vector2f& size, const int no_frames, const int no_states, const float frame_delay, const float move_speed, const int base_life)
	: Character( pos, angle, texture, size, no_frames, no_states, frame_delay, move_speed, base_life )
{

}

bool Enemy::is_at_edge()
{
	const sf::Vector2f current_pos = getPosition();
	if (current_pos.x > Game::GAME_WIDTH - half_texture_size_.x ||
		current_pos.x < -half_texture_size_.x ||
		current_pos.y > Game::GAME_HEIGHT - half_texture_size_.y ||
		current_pos.y < half_texture_size_.y)
		return true;

	return false;
}

void Enemy::handle_edge()
{
	sf::Vector2f current_pos = getPosition();
	if (current_pos.x < -half_texture_size_.x)
		current_pos.x += Game::GAME_WIDTH + half_texture_size_.x * 2;
	setPosition( sf::Vector2f(
		std::max( -half_texture_size_.x,
			std::min( Game::GAME_WIDTH + half_texture_size_.x, current_pos.x ) ),

		std::max( half_texture_size_.y,
			std::min( Game::GAME_HEIGHT - half_texture_size_.y, current_pos.y ) )
	) );
}

void Enemy::on_death()
{
	despawn();
}
