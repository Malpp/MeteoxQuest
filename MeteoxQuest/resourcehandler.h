#pragma once
#include "stdafx.h"

class ResourceHandler
{
public:
	ResourceHandler();
	~ResourceHandler();
	sf::Texture* add_texture(std::string path);
	sf::Uint8* get_mask( sf::Texture* texture );
private:
	std::vector<sf::Texture*> textures_;
	std::map<sf::Texture*, sf::Uint8*> masks_;
};
