#include "stdafx.h"
#include "drawable.h"

void Drawable::delete_()
{
	to_delete_ = true;
}

void Drawable::draw(sf::RenderTarget& window)
{
	window.draw( sprite_ );
}

bool Drawable::should_delete()
{
	return to_delete_;
}

Drawable::Drawable(sf::Vector2f& pos, float angle, sf::Texture* texture)
{
	half_texture_size_ = static_cast<sf::Vector2f>( texture->getSize() ) * 0.5f;
	sprite_.setTexture( *texture );
	sprite_.setOrigin( half_texture_size_ );
	sprite_.setRotation( angle );
	sprite_.setPosition( pos );
	to_delete_ = false;
}
