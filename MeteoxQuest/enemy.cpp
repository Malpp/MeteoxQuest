#include "stdafx.h"
#include "enemy.h"
#include "Game.h"
#include "projectile.h"
#include "player.h"
#include "level_base.h"
#include "explosive_bomb.h";
#include "emp_bomb.h";

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
	const unsigned int score_worth,
	const unsigned int drop_rate)
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
				base_damage_,
				ENEMY)
{
	score_worth_ = score_worth;
	drop_rate_ = drop_rate;
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
	if (should_drop())
	{
		int random_bonus = rand() % 2 + 1;
		switch (random_bonus)
		{
		case 1:
			level->add_game_object(new EmpBomb(getPosition(), 0));
			break;
		case 2:
			level->add_game_object(new ExplosiveBomb(getPosition(), 0));
			break;
		default:
			break;
		}
	}
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

	if (dynamic_cast<Bomb*>(other))
	{
		take_damage( other, level );
	}
}

bool Enemy::should_drop() const
{
	return drop_rate_ >= rand() % 100 + 1;
}

