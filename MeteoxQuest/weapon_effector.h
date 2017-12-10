#pragma once
#include "effector.h"
#include "character.h"

class WeaponEffector : public Effector
{
public:
	explicit WeaponEffector()
		: Effector(live_time_)
	{
	}

	void apply_effector(GameObject* object) override
	{
		if(const auto character = dynamic_cast<Character*>(object))
		{
			character->get_weapon()->jam_weapon();
		}
	}
private:
	static const float live_time_;
};

const float WeaponEffector::live_time_ = 5;
