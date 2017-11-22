#pragma once
#include "stdafx.h"
#include "character.h"

class Enemy : public Character
{
public:
	Enemy( const sf::Vector2f& pos, float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay, float move_speed );

};
