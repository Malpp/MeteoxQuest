#pragma once
#include "stdafx.h"

class CollidableObject : public sf::Sprite
{
public:
	CollidableObject(sf::Texture* texture);
	~CollidableObject();
	const sf::Texture* texture_;
	const sf::Vector2u size_;
	sf::Uint8* mask_;
}; 