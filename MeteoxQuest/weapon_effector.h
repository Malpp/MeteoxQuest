#pragma once
#include "ieffector.h"
#include "character.h"

class WeaponEffector : public IEffector
{
public:
	void apply_effector(GameObject* object) override
	{
		if(const auto character = dynamic_cast<Character*>(object))
		{
			character->
		}
	}
};
