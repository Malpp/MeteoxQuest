#pragma once
#include "stdafx.h"
#include "game_object.h"
#include "character.h"

class Projectile : public GameObject
{
public:
	enum ProjectileType
	{
		PLAYER,
		ENEMY
	};

	Projectile(
		const sf::Vector2f& pos,
		float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		int no_frames,
		int no_states,
		float frame_delay,
		const sf::Vector2f& direction,
		ProjectileType type,
		Color color);
	void update(const float delta_time, LevelBase* level) override;
	void on_death() override;
protected:
	void handle_collision(GameObject* other) override;
	sf::Vector2f direction_;
	bool is_at_edge() override;
	void handle_edge() override;
	static const int base_life_ = 1;
	ProjectileType type_;
};
