#pragma once
#include "ieffector.h"

class MovementEffector : public IEffector
{
public:
	void apply_effector(GameObject* object) override
	{
		object->velocity_ *= 0.5f;
	}
};
