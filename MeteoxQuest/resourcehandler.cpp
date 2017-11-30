#include "stdafx.h"
#include "resourcehandler.h"

ResourceHandler::ResourceHandler()
{
}

ResourceHandler::~ResourceHandler()
{
	for(sf::Texture* texture : textures_)
	{
		delete texture;
	}
}

sf::Texture* ResourceHandler::add_texture(const std::string path)
{
	sf::Texture* texture_to_load_ = new sf::Texture;
	if(!texture_to_load_->loadFromFile("Assets/" + path))
	{
		delete texture_to_load_;
		throw std::invalid_argument(path + " not found");
	}
	textures_.push_back(texture_to_load_);
	return texture_to_load_;
}
