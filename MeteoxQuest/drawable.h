#pragma once
#include "stdafx.h"

class Drawable
{
public:
	virtual void delete_();
	virtual void draw(sf::RenderTarget& window);
	bool should_delete();
protected:
	Drawable( sf::Vector2f& pos, float angle, sf::Texture* texture );
	sf::Sprite sprite_;
	sf::Vector2f half_texture_size_;
private:
	bool to_delete_;
};