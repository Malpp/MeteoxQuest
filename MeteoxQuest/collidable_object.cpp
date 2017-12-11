#include "stdafx.h"
#include "colliable_object.h"
#include "Game.h"

CollidableObject::CollidableObject(sf::Texture* texture)
	: texture_(texture)
	, size_(texture->getSize())
{
	mask_ = Game::resource_handler_.get_mask(texture);
}

CollidableObject::~CollidableObject()
{
}
