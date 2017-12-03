#pragma once

struct Command
{
	const float command_duration_ = 0.15f;

	Command(const int move)
		: move_(move)
		, time_remaining_(command_duration_)
	{
	}

	int move_;
	float time_remaining_;
};

//const float Command::command_duration_ = 0.3f;
