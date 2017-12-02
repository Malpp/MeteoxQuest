#pragma once

struct Command
{
	Command(const int move)
		: move(move)
		, time_remaining_(command_duration_)
	{
	}

	int move;
	float time_remaining_;

	const float command_duration_ = 0.3f;
};

//const float Command::command_duration_ = 0.3f;
