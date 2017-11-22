#include "stdafx.h"
#include "enemy.h"

Enemy::Enemy(const sf::Vector2f& pos, float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay, float move_speed)
	: Character( pos, angle, texture, size, no_frames, no_states, frame_delay, move_speed )
{

}
