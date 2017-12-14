#include "stdafx.h"
#include "shield.h"
#include "player.h"

sf::Texture* Shield::shield_texture;
const float Shield::frame_delay_ = 0.01f;
const float Shield::movespeed_ = 0;
const sf::Vector2f Shield::size_ = sf::Vector2f(146, 88);

Shield::Shield(Player* player)
	: GameObject(player->getPosition(),
	             player->getRotation(),
	             shield_texture,
	             size_,
	             no_frames_,
	             no_states_,
	             frame_delay_,
	             base_life_,
	             generate_random_color(),
	             base_damage_,
	             PLAYER
	)
	, player_(player)
{
	sf::Color color;
	switch(color_)
	{
		case BLUE:
			color = sf::Color::Blue;
			break;
		case RED:
			color = sf::Color::Red;
			break;
		case GREEN:
			color = sf::Color::Green;
			break;
		default:
			color = sf::Color::White;
			break;
	}
	setColor(color);
}

void Shield::update(const float delta_time)
{
	setPosition(player_->getPosition());
}

void Shield::handle_collision(GameObject* other, LevelBase* level)
{
}

void Shield::on_death(LevelBase* level)
{
}
