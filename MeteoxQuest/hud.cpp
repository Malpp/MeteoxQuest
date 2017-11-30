#include "stdafx.h"
#include "hud.h"
#include "player.h"

Hud::Hud()
{
}

void Hud::notifier(Subject* subject)
{
	if(auto player = dynamic_cast<Player*>(subject))
	{
		score_ = player->get_score();
		life_ = player->get_life();
	}
}
