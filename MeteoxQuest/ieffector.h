#pragma once
#include "game_object.h"

class IEffector
{
public:
	virtual void apply_effector(GameObject* object) = 0;
};
