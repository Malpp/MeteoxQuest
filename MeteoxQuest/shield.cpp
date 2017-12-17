#include "stdafx.h"
#include "shield.h"
#include "player.h"

sf::Texture* Shield::shield_texture;
const float Shield::frame_delay_ = 0.1f;
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
	set_color_to_match();
}

void Shield::update(const float delta_time, LevelBase* level)
{
	setPosition(player_->getPosition());
	GameObject::update(delta_time, level);
}

void Shield::handle_collision(GameObject* other, LevelBase* level)
{
}

void Shield::on_death(LevelBase* level)
{
	despawn();
}

void Shield::handle_edge()
{
}
