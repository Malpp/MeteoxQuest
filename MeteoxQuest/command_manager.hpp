#pragma once
#include "stdafx.h"
#include "command.hpp"

class CommandManager
{
	friend class Player;
public:
	~CommandManager()
	{
		for(auto& command : commands_)
		{
			delete command;
		}
	}

	void update(const float delta_time)
	{
		for(int i = commands_.size() - 1; i -- > 0;)
		{
			commands_[i]->time_remaining_ -= delta_time;

			if(commands_[i]->time_remaining_ < 0)
			{
				delete commands_[i];
				commands_.erase(commands_.begin() + i);
			}
		}
	}

	void add(Command* manip)
	{
		commands_.push_back(manip);
	}

	void remove_valid_command()
	{
		//lul wat
		for(int i = 0; i < 3; ++i)
		{
			remove_first();
		}
	}

	void remove_first()
	{
		delete commands_[0];
		commands_.erase(commands_.begin(), commands_.begin() + 1);
	}

private:
	std::vector<Command*> commands_;
};
