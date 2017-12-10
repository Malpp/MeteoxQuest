#pragma once
#include "effector.h"
#include "game_object.h"

class MovementEffector : public Effector
{
public:
	explicit MovementEffector()
		: Effector(live_time_)
	{
	}

	void apply_effector(GameObject* object) override
	{
		object->velocity_ *= 0.5f;
	}
private:
	static const float live_time_;
};

const float MovementEffector::live_time_ = 5;