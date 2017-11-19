#include "stdafx.h"
#include "resourcehandler.h"
#include <windows.h>

ResourceHandler::ResourceHandler()
{

}

ResourceHandler::~ResourceHandler()
{
	for (sf::Texture* texture : textures_)
	{
		delete texture;
	}
}

sf::Texture* ResourceHandler::add_texture(std::string path)
{
	sf::Texture* texture_to_load_ = new sf::Texture;
	TCHAR pwd[MAX_PATH];
	GetCurrentDirectory( MAX_PATH, pwd );
	//MessageBox( NULL, pwd, pwd, 0 );
	if (!texture_to_load_->loadFromFile( "Assets/" + path ))
	{
		delete texture_to_load_;
		throw std::invalid_argument( path + " not found" );
	}
	textures_.push_back( texture_to_load_ );
	return texture_to_load_;
}
