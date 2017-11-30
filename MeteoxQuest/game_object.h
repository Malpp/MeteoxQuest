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
	void take_damage(const GameObject* object, LevelBase* level);
	GameObject(
		const sf::Vector2f pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		const int no_frames,
		const int no_states,
		const float frame_delay,
		const int life,
		Color color,
		const int damage);
	~GameObject();
	void collision_test(GameObject* other, LevelBase* level);
	static Color generate_random_color();
protected:
	virtual void handle_collision(GameObject* other, LevelBase* level) = 0;
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
	int life_;
	int damage_;
	virtual void on_death(LevelBase* level) = 0;
	float biggest_texture_side_;
	Color color_;
};
