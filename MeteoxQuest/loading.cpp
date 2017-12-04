#include "stdafx.h"
#include "loading.h"
#include "Game.h"
#include "cloud9_enemy.h"
#include "emp_bomb.h"
#include "GC_enemy.h"
#include <windows.h>

Loading::Loading(sf::RenderWindow* window)
	: Scene(window)
	, loading_bar_(sf::Vector2f(0, Game::GAME_HEIGHT))
{
	current_element_ = 0;
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
		case elements_to_load_:
			change_scene(MENU);
			break;
	}
	++current_element_;
	loading_bar_.setSize(sf::Vector2f(Game::GAME_WIDTH * (static_cast<float>(
											current_element_) /
										static_cast<float>(elements_to_load_)),
									Game::GAME_HEIGHT));
}

void Loading::draw()
{
	window_->clear();

	window_->draw(loading_bar_);

	window_->display();
}
