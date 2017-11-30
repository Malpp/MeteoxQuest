#include "stdafx.h"
#include "enemy.h"
#include "Game.h"
#include "projectile.h"
#include "player.h"
#include "level_base.h"

Enemy::Enemy(
	const sf::Vector2f& pos,
	const float angle,
	sf::Texture* texture,
	const sf::Vector2f& size,
	const int no_frames,
	const int no_states,
	const float frame_delay,
	const float move_speed,
	const int base_life,
	const Color color,
	const unsigned int score_worth)
	: Character(pos,
				angle,
				texture,
				size,
				no_frames,
				no_states,
				frame_delay,
				move_speed,
				base_life,
				color,
				base_damage_)
{
	score_worth_ = score_worth;
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
	setPosition(sf::Vector2f(
		std::max(-half_texture_size_.x,
				std::min(Game::GAME_WIDTH + half_texture_size_.x,
						current_pos.x)),

		std::max(half_texture_size_.y,
				std::min(Game::GAME_HEIGHT - half_texture_size_.y,
						current_pos.y))
	));
}

void Enemy::on_death(LevelBase* level)
{
	level->add_score( score_worth_ );
	despawn();
}

void Enemy::handle_collision(GameObject* other, LevelBase* level)
{
	if (dynamic_cast<Projectile*>(other) && dynamic_cast<Projectile*>(other)->get_type() == Projectile::PLAYER)
	{
		take_damage( other, level);
	}

	if (dynamic_cast<Player*>(other))
	{
		despawn();
	}
}
