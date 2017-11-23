#include "stdafx.h"
#include "game_object.h"
#include "Game.h"
#include "level_base.h"

void GameObject::update(const float delta_time, LevelBase* level)
{
	move( velocity_ * delta_time );

	frame_timer_ += delta_time;
	if(frame_timer_ > frame_time_)
	{
		frame_timer_ = 0;
		++frame_;
	}

	setTextureRect( player_animations_[state_][frame_ % max_frame_] );

	if (is_at_edge())
	{
		handle_edge();
	}
	velocity_.x = 0;
	velocity_.y = 0;
}

void GameObject::despawn()
{
	should_despawn = true;
}

bool GameObject::get_despawn() const
{
	return should_despawn;
}

GameObject::GameObject( const sf::Vector2f pos, const float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay )
{
	setPosition( pos );
	setRotation( angle );
	setTexture( *texture );
	state_ = 0;
	frame_ = 0;
	max_state_ = no_states;
	max_frame_ = no_frames;
	frame_time_ = frame_delay;
	frame_timer_ = 0;
	should_despawn = false;
	velocity_ = sf::Vector2f( 0, 0 );
	half_texture_size_ = size * 0.5f;
	player_animations_ = new sf::IntRect*[no_states];
	for (int state = 0; state < no_states; ++state)
	{
		player_animations_[state] = new sf::IntRect[no_frames];
		for (int frame = 0; frame < no_frames; ++frame)
		{
			player_animations_[state][frame] = sf::IntRect(
				size.x * frame,
				size.y * state,
				size.x,
				size.y );
		}
	}
	setTextureRect( player_animations_[0][0] );
	setOrigin( half_texture_size_.x, half_texture_size_.y );
}

GameObject::~GameObject()
{
	for (int state = 0; state < max_state_; ++state)
	{
		delete[] player_animations_[state];
	}
	delete[] player_animations_;
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
