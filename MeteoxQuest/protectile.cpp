#include "stdafx.h"
#include "projectile.h"
#include "Game.h"
#include "character.h"
#include "player.h"
#include "enemy.h"

Projectile::Projectile(
	const sf::Vector2f& pos,
	const float angle,
	sf::Texture* texture,
	const sf::Vector2f& size,
	const int no_frames,
	const int no_states,
	const float frame_delay,
	const sf::Vector2f& direction,
	const GameType type,
	const Color color)
	: NonCharacter(pos,
	             angle,
	             texture,
	             size,
	             no_frames,
	             no_states,
	             frame_delay,
	             base_life_,
	             color,
	             base_damage_,
	             type)
{
	direction_ = direction;
}

void Projectile::on_death(LevelBase* level)
{
	despawn();
}

void Projectile::handle_collision(GameObject* other, LevelBase* level)
{
	if(dynamic_cast<Player*>(other) && type_ == ENEMY)
	{
		take_damage(other, level);
	}

	if(dynamic_cast<Enemy*>(other) && type_ == PLAYER)
	{
		take_damage(other, level);
	}
}
