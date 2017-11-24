#pragma once
#include "stdafx.h"
#include "game_object.h"
#include "character.h"

class Projectile : public GameObject
{
public:
	Projectile( const sf::Vector2f& pos, float angle, sf::Texture* texture, const sf::Vector2f& size, int no_frames, int no_states, float frame_delay, const sf::Vector2f& direction );
	void update(const float delta_time, LevelBase* level) override;
	void on_death() override;
protected:
	sf::Vector2f direction_;
	bool is_at_edge() override;
	void handle_edge() override;
	static const int base_life_ = 1;
};
