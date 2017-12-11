#pragma once
#include "powerup.h"

class Bomb : public PowerUp
{
public:
	enum BombState
	{
		SEEKING,
		ORBIT,
		LAUNCH
	};

	Bomb(
		const sf::Vector2f& pos,
		const float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		const int no_frames,
		const int no_states,
		const float frame_delay,
		const float movespeed);
	bool launch(GameObject* other);
	void update(const float delta_time, LevelBase* level) override;
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
	BombState state_;
	void handle_edge() override;
private:
	static const float orbit_speed_;
	static const float max_orbit_distance_;
	static const float orbit_correction_speed_;
	float orbit_distance_;
	GameObject* orbit_center_;
	float orbit_counter_;
};
