#pragma once
#include "stdafx.h"

class GameObject : sf::Sprite
{
public:
	virtual void update(const float delta_time );
protected:
	GameObject(const sf::Vector2f pos, const float angle, sf::Texture* texture);
	virtual sf::Vector2f get_next_move( float delta_time ) = 0;
	virtual bool is_at_edge();
	virtual void handle_edge();
	sf::Vector2f velocity_;
	sf::Vector2f half_texture_size_;
};
