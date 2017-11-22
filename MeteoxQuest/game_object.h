#pragma once
#include "stdafx.h"

class GameObject : public  sf::Sprite
{
public:
	virtual void update( const float delta_time );
	void despawn();
	bool get_despawn() const;
	GameObject( const sf::Vector2f pos, const float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay );
	~GameObject();
protected:
	virtual bool is_at_edge();
	virtual void handle_edge();
	sf::Vector2f velocity_;
	sf::Vector2f half_texture_size_;
	unsigned int state_;
	unsigned int frame_;
	unsigned int max_state_;
	unsigned int max_frame_;
	sf::IntRect** player_animations_;
	float frame_timer_;
	float frame_time_;
	bool should_despawn;
};
