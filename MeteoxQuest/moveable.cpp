#include "stdafx.h"
#include "moveable.h"
#include "Game.h"

void GameObject::update(const float delta_time )
{
	move(velocity_ * delta_time);

	if(is_at_edge())
	{
		handle_edge();
	}
}

GameObject::GameObject(const sf::Vector2f pos, const float angle, sf::Texture* texture)
{
	setPosition(pos);
	setRotation(angle);
	velocity_ = sf::Vector2f(0, 0);
	half_texture_size_ = static_cast<sf::Vector2f>(texture->getSize()) * 0.5f;
}

bool GameObject::is_at_edge()
{
	const sf::Vector2f current_pos = getPosition();
	if (current_pos.x > Game::GAME_WIDTH - half_texture_size_.x ||
		current_pos.x < half_texture_size_.x ||
		current_pos.y > Game::GAME_HEIGHT - half_texture_size_.y ||
		current_pos.y < half_texture_size_.y)
		return true;

	return false;
}

void GameObject::handle_edge()
{
	const sf::Vector2f current_pos = getPosition();
	setPosition( sf::Vector2f(
		std::max( half_texture_size_.x,
			std::min( Game::GAME_WIDTH - half_texture_size_.x, current_pos.x ) ),

		std::max( half_texture_size_.y,
			std::min( Game::GAME_HEIGHT - half_texture_size_.y, current_pos.y ) )
	) );
}
