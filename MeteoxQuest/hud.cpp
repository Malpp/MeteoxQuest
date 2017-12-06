#include "stdafx.h"
#include "hud.h"
#include "player.h"
#include "Game.h"

sf::Texture* Hud::player_icon_texture_ = Game::resource_handler_.add_texture("player_icon.png");

Hud::Hud()
	: life_(0)
	, score_(0)
	, score_text_("0", Game::font)
	, life_text_("", Game::font)
{
	player_icon_.setPosition(10, 50);
	player_icon_.setTexture(*player_icon_texture_);
	score_text_.setPosition(10, 10);
	life_text_.setPosition(95, 55);

}

void Hud::draw(sf::RenderWindow* window) const
{
	window->draw(player_icon_);
	window->draw(score_text_);
	window->draw(life_text_);
}

void Hud::notifier(Subject* subject)
{
	if(const auto player = dynamic_cast<Player*>(subject))
	{
		std::stringstream score_stream;
		score_stream << player->get_score();
		score_text_.setString("SCORE: " + score_stream.str());

		std::stringstream life_stream;
		const int life = player->get_life();
		life_stream << ((life < 0) ? "-" : "") << life;
		life_text_.setString("X " + life_stream.str());
	}
}
