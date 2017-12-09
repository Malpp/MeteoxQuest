#pragma once
#include "stdafx.h"
#include "character.h"
#include "subject.h"
#include "list.h"
#include "command_manager.hpp"
#include "powerup.h"
#include "bomb.h"

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
	void add_powerup( const PowerUp::PowerUpType power_up );
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
private:
	void do_dashes(const float delta_time);
	static const int base_damage_ = 1;
	static sf::Texture* texture_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 4;
	static const float movespeed_;
	static const float frame_delay_;
	static const int base_life_ = 3;
	unsigned int score_;
	list<Weapon*> weapons;
	CommandManager command_manager_;
	unsigned last_state_;
	float idle_timer_;
	static const float max_idle_time_;
	static const float dash_speed_;
	static const float dash_duration_;
	static const float dash_cooldown_;
	float dash_cooldown_timer_;
	float dash_timer_;
	bool dashing_;
	bool dash_ready_;
	sf::Vector2f dash_direction_;
	std::vector<Bomb*> bombs_;
	bool bomb_launched_;
};
