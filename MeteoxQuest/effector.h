#pragma once

class GameObject;

class Effector
{
public:
	Effector(const float live_time_)
		: time_remaining_(live_time_)
		, should_despawn_(false)
	{
	}
	virtual void apply_effector(GameObject* object) = 0;
	void update(const float delta_time)
	{
		time_remaining_ -= delta_time;
		if(time_remaining_ < 0)
			should_despawn_ = true;
	}
	bool should_despawn() const
	{
		return should_despawn_;
	}
private:
	float time_remaining_;
	bool should_despawn_;
};
