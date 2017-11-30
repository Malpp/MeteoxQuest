#include "stdafx.h"
#include "colliable_object.h"

CollidableObject::CollidableObject(sf::Texture* texture)
	: texture_(texture), size_(texture->getSize())
{
	mask_ = new sf::Uint8[size_.y * size_.x];
	sf::Image img = texture->copyToImage();

	for(unsigned int y = 0; y < size_.y; y++)
	{
		for(unsigned int x = 0; x < size_.x; x++)
			mask_[x + y * size_.x] = img.getPixel(x, y).a;
	}
}

CollidableObject::~CollidableObject()
{
	delete mask_;
}
