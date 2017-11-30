#pragma once
#include "iobserver.h"

class Hud : IObserver
{
public:
	Hud();
	void notifier(Subject* subject) override;
private:
	int life_;
	unsigned int score_;
};
