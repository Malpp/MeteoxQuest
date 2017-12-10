#pragma once
#include "player_projectile.h"

class EmpBlast : public PlayerProjectile
{
public:
	EmpBlast(const sf::Vector2f& pos,
			float angle);
	void update(const float delta_time, LevelBase* level) override;
	static sf::Texture* texture_;
	void on_death(LevelBase* level) override;
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
private:
	static const std::string texture_name_;
	static const sf::Vector2f size_;
	static const int no_frames_ = 8;
	static const int no_states_ = 1;
	static const int damage_ = 0;
	static const float movespeed_;
	static const float frame_delay_;
	std::vector<GameObject*> effected_objects_;
};
