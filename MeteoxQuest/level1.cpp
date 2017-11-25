#include "stdafx.h"
#include "level1.h"
#include "GC_enemy.h"
#include "orc_enemy.h"
#include "ken_enemy.h"
#include "Game.h"

sf::Texture* Level1::texture_ = Game::resource_handler_.add_texture( "level1.png" );

Level1::Level1(sf::RenderWindow* window)
	: LevelBase(window, texture_, 300)
{
	add_game_object( new GCEnemy( sf::Vector2f( 1300, 300 ), 0 ) );
	add_game_object( new OrcEnemy( sf::Vector2f( 1300, 700 ), 0 ) );
	add_game_object( new KenEnemy( sf::Vector2f( 1300, 700 ), 0 ) );
}

void Level1::update(float delta_time)
{
	LevelBase::update( delta_time );
}