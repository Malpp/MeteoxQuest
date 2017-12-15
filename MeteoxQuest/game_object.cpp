#include "stdafx.h"
#include "Game.h"
#include "game_object.h"
#include "level_base.h"
#include "helper.h"
#include "collision.h"

void GameObject::update(const float delta_time, LevelBase* level)
{
	for(int i = effectors_.size() - 1; i >= 0; --i)
	{
		effectors_[i]->apply_effector(this);
		effectors_[i]->update(delta_time);
		if(effectors_[i]->should_despawn())
		{
			delete effectors_[i];
			effectors_.erase(effectors_.begin() + i);
		}
	}

	move(velocity_ * delta_time);

	frame_timer_ += delta_time;
	if(frame_timer_ > frame_time_)
	{
		frame_timer_ = 0;
		++frame_;
	}

	setTextureRect(player_animations_[state_][frame_ % max_frame_]);

	if(is_at_edge())
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

GameObject::GameObject(
	const sf::Vector2f pos,
	const float angle,
	sf::Texture* texture,
	const sf::Vector2f& size,
	const int no_frames,
	const int no_states,
	const float frame_delay,
	const int life,
	const Color color,
	const int damage,
	const GameType type)
	: CollidableObject(texture)
{
	type_ = type;
	color_ = color;
	setPosition(pos);
	setRotation(angle);
	setTexture(*texture);
	life_ = life;
	damage_ = damage;
	state_ = 0;
	frame_ = 0;
	max_state_ = no_states;
	max_frame_ = no_frames;
	frame_time_ = frame_delay;
	frame_timer_ = 0;
	should_despawn = false;
	velocity_ = sf::Vector2f(0, 0);
	half_texture_size_ = size * 0.5f;
	player_animations_ = new sf::IntRect*[no_states];
	for(int state = 0; state < no_states; ++state)
	{
		player_animations_[state] = new sf::IntRect[no_frames];
		for(int frame = 0; frame < no_frames; ++frame)
		{
			player_animations_[state][frame] = sf::IntRect(
				size.x * frame,
				size.y * state,
				size.x,
				size.y);
		}
	}
	setTextureRect(player_animations_[0][0]);
	setOrigin(half_texture_size_.x, half_texture_size_.y);
	biggest_texture_side_ = std::max(half_texture_size_.x,
	                                 half_texture_size_.y);
}

GameObject::~GameObject()
{
	for(int state = 0; state < max_state_; ++state)
	{
		delete[] player_animations_[state];
	}
	delete[] player_animations_;
	for(Effector* effector : effectors_)
	{
		delete effector;
	}
}

void GameObject::collision_test(GameObject* other, LevelBase* level)
{
	if(type_ != other->type_)
	{
		if(Helper::distanceBetweenTwoPoints(getPosition(), other->getPosition())
			<
			biggest_texture_side_ + other->biggest_texture_side_)
		{
			if(Collision::PixelPerfectTest(*this, *other))
			{
				handle_collision(other, level);
				other->handle_collision(this, level);
			}
		}
	}
}

GameObject::Color GameObject::generate_random_color()
{
	return static_cast<Color>(Helper::generateRandInt(RED, BLUE));
}

GameObject::GameType GameObject::get_type() const
{
	return type_;
}

void GameObject::add_effector(Effector* effector)
{
	effectors_.push_back(effector);
}

int GameObject::get_life() const
{
	return life_;
}

int GameObject::get_damage() const
{
	return damage_;
}

void GameObject::set_color_to_match()
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

bool GameObject::is_at_edge()
{
	const sf::Vector2f current_pos = getPosition();
	if(current_pos.x > Game::GAME_WIDTH - half_texture_size_.x ||
		current_pos.x < half_texture_size_.x ||
		current_pos.y > Game::GAME_HEIGHT - half_texture_size_.y ||
		current_pos.y < half_texture_size_.y)
		return true;

	return false;
}

void GameObject::handle_edge()
{
	const sf::Vector2f current_pos = getPosition();
	setPosition(sf::Vector2f(
		std::max(half_texture_size_.x,
		         std::min(Game::GAME_WIDTH - half_texture_size_.x,
		                  current_pos.x)),

		std::max(half_texture_size_.y,
		         std::min(Game::GAME_HEIGHT - half_texture_size_.y,
		                  current_pos.y))
	));
}

int GameObject::take_damage(const GameObject* object, LevelBase* level, const int damage)
{
	if(color_ == object->color_)
		life_ += damage ? damage : object->damage_;
	else
		life_ -= damage ? damage : object->damage_;

	if(life_ < 1)
	{
		on_death(level);
		return std::abs(life_);
	}
	return -1;
}
