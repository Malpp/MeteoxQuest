#include "stdafx.h"
#include "resourcehandler.h"

ResourceHandler::ResourceHandler()
{
}

ResourceHandler::~ResourceHandler()
{
	for(sf::Texture* texture : textures_)
	{
		delete[] masks_.at( texture );
		delete texture;
	}
}

sf::Texture* ResourceHandler::add_texture(const std::string path)
{
	sf::Texture* texture_to_load = new sf::Texture;
	if(!texture_to_load->loadFromFile("Assets/" + path))
	{
		delete texture_to_load;
		throw std::invalid_argument(path + " not found");
	}
	textures_.push_back(texture_to_load);

	const sf::Vector2u size = texture_to_load->getSize();
	sf::Uint8* mask = new sf::Uint8[size.y * size.x];
	sf::Image img = texture_to_load->copyToImage();

	for (unsigned int y = 0; y < size.y; y++)
	{
		for (unsigned int x = 0; x < size.x; x++)
			mask[x + y * size.x] = img.getPixel( x, y ).a;
	}

	masks_.insert_or_assign( texture_to_load, mask );
	return texture_to_load;
}

sf::Uint8* ResourceHandler::get_mask(sf::Texture* texture)
{
	return masks_.at( texture );
}
