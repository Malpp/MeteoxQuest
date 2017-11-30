#include "stdafx.h"
#include "hud.h"
#include "player.h"
#include "Game.h"

Hud::Hud()
	: life_(0)
	, score_(0)
	, score_text_("0", Game::font)
	, life_text_("", Game::font)
{
	score_text_.setPosition(0, 0);
	life_text_.setPosition(0, 35);
}

void Hud::draw(sf::RenderWindow* window) const
{
	window->draw(score_text_);
	window->draw(life_text_);
}

void Hud::notifier(Subject* subject)
{
	if(const auto player = dynamic_cast<Player*>(subject))
	{
		std::stringstream score_stream;
		score_stream << player->get_score();
		score_text_.setString(score_stream.str());

		std::stringstream life_stream;
		const int life = player->get_life();
		life_stream << ((life < 0) ? "-" : "") << life;
		life_text_.setString(life_stream.str());
	}
}
