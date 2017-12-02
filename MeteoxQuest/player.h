#pragma once
#include "stdafx.h"
#include "character.h"
#include "subject.h"

class LevelBase;

class Player : public Character, public Subject
{
	friend class PowerUp;
public:
	enum PlayerState
	{
		IDLE,
		LEFT,
		RIGHT,
		UP,
		DOWN,
		COUNT
	};
	unsigned get_score() const;
	void add_score(const int score_to_add);
	int get_life() const;
	Player(const sf::Vector2f& pos, const float angle);
	void update(const float delta_time, LevelBase* level) override;
	void up() override;
	void down() override;
	void left() override;
	void right() override;
	void on_death(LevelBase* level) override;
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
private:
	static const int base_damage_ = 1;
	static sf::Texture* texture_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 4;
	static const float movespeed_;
	static const float frame_delay_;
	static const int base_life_ = 3;
	unsigned int score_;
};
