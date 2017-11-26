#pragma once
#include "stdafx.h"

class LevelBase;

class GameObject : public sf::Sprite
{
public:
	enum Color
	{
		RED,
		GREEN,
		BLUE,
		NONE,
		RANDOM
	};

	virtual void update(const float delta_time, LevelBase* level);
	void despawn();
	bool get_despawn() const;
	void take_damage(const int damage);
	GameObject(
		const sf::Vector2f pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		int no_frames,
		int no_states,
		float frame_delay,
		const int life,
		Color color);
	~GameObject();
	void collision_test(GameObject* other);
	static Color generate_random_color();
protected:
	virtual void handle_collision(GameObject* other) = 0;
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
	int life;
	virtual void on_death() = 0;
	float biggest_texture_side_;
	Color color_;
};
