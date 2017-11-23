#include "stdafx.h"
#include "GC_enemy.h"
#include "Game.h"
#include "gc_projectile.h"
#include "level_base.h"

sf::Texture* GCEnemy::texture_ = Game::resource_handler_.add_texture("gc_enemy.png");
const sf::Vector2f GCEnemy::size_ = sf::Vector2f( 105, 75 );
const float GCEnemy::movespeed_ = 600;
const float GCEnemy::fire_speed_ = 1;
const float GCEnemy::frame_delay_ = 0.1f;

GCEnemy::GCEnemy( const sf::Vector2f& pos, const float angle )
	: Enemy( pos, angle, texture_, size_, no_frames_, no_states_, frame_delay_, movespeed_, fire_speed_)
{

}

void GCEnemy::update(const float delta_time, LevelBase* level)
{
	left();
	fire(level);
	Enemy::update( delta_time, level);
}

void GCEnemy::handle_fire(LevelBase* level)
{
	level->add_game_object(new GCProjectile(getPosition(), 0, sf::Vector2f(-1, 0)));
}
