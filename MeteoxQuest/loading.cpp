#include "stdafx.h"
#include "loading.h"
#include "Game.h"
#include "cloud9_enemy.h"
#include "emp_bomb.h"
#include "GC_enemy.h"
#include "emp_projectile.h"
#include "hud.h"
#include "explosive_projectile.h"
#include "explosive_bomb.h"
#include "shield.h"
#include "player.h"
#include "heart_weapon.h"
#include "mario_weapon.h"
#include "shield_powerup.h"

Loading::Loading(sf::RenderWindow* window)
	: Scene(window)
	, loading_bar_()
{
	current_element_ = 0;
	Game::font.loadFromFile("Assets//emulogic.ttf");
	loading_bar_.setSize(sf::Vector2f(Game::GAME_WIDTH * (static_cast<float>(
			                                  current_element_) /
		                                  static_cast<float>(elements_to_load_)),
	                                  Game::GAME_HEIGHT * 0.1f));
	loading_bar_.setOrigin(0, Game::GAME_HEIGHT * 0.1f * 0.5f);
	loading_bar_.setPosition(0, Game::GAME_HEIGHT);
}

void Loading::input()
{
}

void Loading::update(float delta_time)
{
	switch(current_element_)
	{
		case 0:
			Cloud9Enemy::textures_[0] =
					Game::resource_handler_.
					add_texture(Cloud9Enemy::texture_name_ + "red.png");
			break;
		case 1:
			Cloud9Enemy::textures_[1] = Game::resource_handler_.
					add_texture(Cloud9Enemy::texture_name_ + "green.png");
			break;
		case 2:
			Cloud9Enemy::textures_[2] = Game::resource_handler_.
					add_texture(Cloud9Enemy::texture_name_ + "blue.png");
			break;
		case 3:
			EmpBomb::texture_ = Game::resource_handler_.add_texture("emp_bomb.png");
			break;
		case 4:
			GCEnemy::textures_[0] =
					Game::resource_handler_.
					add_texture(GCEnemy::texture_name_ + "red.png");
			break;
		case 5:
			GCEnemy::textures_[1] = Game::resource_handler_.
					add_texture(GCEnemy::texture_name_ + "green.png");
			break;
		case 6:
			GCEnemy::textures_[2] = Game::resource_handler_.
					add_texture(GCEnemy::texture_name_ + "blue.png");
			break;
		case 7:
			EmpBlast::texture_ = Game::resource_handler_.
					add_texture("emp_blast.png");
			break;
		case 8:
			Hud::player_icon_texture_ = Game::resource_handler_.
					add_texture("hud/player_icon.png");
			break;
		case 9:
			Hud::heart_icon_texture_ = Game::resource_handler_.
					add_texture("hud/heart_icon.png");
			break;
		case 10:
			Hud::mario_icon_texture_ = Game::resource_handler_.
					add_texture("hud/mario_icon.png");
			break;
		case 11:
			Hud::incoming_arrow_ = Game::resource_handler_.
					add_texture("hud/arrow.png");
			break;
		case 12:
			Hud::incoming_warning_ = Game::resource_handler_.
					add_texture("hud/warning.png");
			break;
		case 13:
			ExplosiveBlast::texture_ = Game::resource_handler_.
					add_texture("bomb_explosion.png");
			break;
		case 14:
			ExplosiveBomb::texture_ = Game::resource_handler_.
					add_texture("explosive_bomb.png");
			break;
		case 15:
			Shield::shield_texture = Game::resource_handler_.
					add_texture("shield.png");
			break;
		case 16:
			Player::player_hit_sound.loadFromFile("Assets/Sounds/hit.ogg");
			break;
		case 17:
			HeartWeapon::fire_sound.loadFromFile("Assets/Sounds/heart.ogg");
			break;
		case 18:
			MarioWeapon::fire_sound.loadFromFile("Assets/Sounds/mario.wav");
			break;
		case 19:
			ShieldPowerup::texture_ = Game::resource_handler_.
					add_texture("shield_powerup.png");
			break;
		default:
			change_scene(MENU);
			break;
	}
	++current_element_;
	loading_bar_.setSize(sf::Vector2f(Game::GAME_WIDTH * (static_cast<float>(
			                                  current_element_) /
		                                  static_cast<float>(elements_to_load_)),
	                                  Game::GAME_HEIGHT * 0.1f));
}

void Loading::draw()
{
	window_->draw(loading_bar_);
	window_->draw(text_);
}
