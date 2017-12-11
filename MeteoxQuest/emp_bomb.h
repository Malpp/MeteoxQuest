#pragma once
#include "bomb.h"

class EmpBomb : public Bomb
{
public:
	EmpBomb(const sf::Vector2f& pos,
			const float angle);
	static sf::Texture* texture_;
	static const std::string texture_name_;
protected:
	void on_death(LevelBase* level) override;
private:
	static const sf::Vector2f size_;
	static const int no_frames_ = 1;
	static const int no_states_ = 1;
	static const float movespeed_;
	static const float frame_delay_;
};
