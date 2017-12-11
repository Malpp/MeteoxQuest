#include "stdafx.h"
#include "hud.h"
#include "player.h"
#include "Game.h"
#include "level_base.h"
#include "heart_weapon.h"
#include "mario_weapon.h"

sf::Texture* Hud::player_icon_texture_;
sf::Texture* Hud::heart_icon_texture_;
sf::Texture* Hud::mario_icon_texture_;
//sf::Texture* Hud::roller_coaster_icon_texture_;
sf::Texture* Hud::incoming_arrow_;
sf::Texture* Hud::incoming_warning_;
const float Hud::blink_time_ = 0.2f;

Hud::Hud()
	: life_(0)
	, score_(0)
	, score_text_("0", Game::font)
	, life_text_("", Game::font)
	, blink_timer_(0)
	, should_draw_(false)
	, warning_sprite_(*incoming_warning_)
	, wave_incoming_(false)
	, arrows_created_(false)
	, wave_size_(0)
	, arrow_screen_offset_(incoming_arrow_->getSize().y * 0.5f)
	, selected_weapon_(26)
{
	player_icon_.setPosition(10, 50);
	player_icon_.setTexture(*player_icon_texture_);
	heart_weapon_icon_.setTexture(*heart_icon_texture_);
	heart_weapon_icon_.setPosition(1600, 20);
	mario_weapon_icon_.setTexture(*mario_icon_texture_);
	mario_weapon_icon_.setPosition(1675, 20);
	score_text_.setPosition(10, 10);
	life_text_.setPosition(95, 55);
	selected_weapon_.setFillColor(sf::Color::Transparent);
	selected_weapon_.setOutlineColor(sf::Color::White);
	selected_weapon_.setOutlineThickness(5);

	for(int i = 0; i < number_of_arrows_; ++i)
	{
		arrows[i].setTexture(*incoming_arrow_);
		arrows[i].setOrigin( static_cast<sf::Vector2f>(incoming_arrow_->getSize()) * 0.5f );
	}
}

void Hud::draw(sf::RenderWindow* window) const
{
	window->draw(player_icon_);
	window->draw(heart_weapon_icon_);
	window->draw(mario_weapon_icon_);
	window->draw(selected_weapon_);
	window->draw(score_text_);
	window->draw(life_text_);
	if(should_draw_)
	{
		window->draw(warning_sprite_);
	}
	if(wave_incoming_)
	{
		for(int i = 0; i < wave_size_; ++i)
		{
			window->draw(arrows[i]);
		}
	}
}

void Hud::notifier(Subject* subject, const float delta_time)
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

		if (const auto weapon = dynamic_cast<HeartWeapon*>(player->get_weapon()))
		{
			selected_weapon_.setPosition(1598, 14);
		}
		else if (const auto weapon = dynamic_cast<MarioWeapon*>(player->get_weapon()))
		{
			selected_weapon_.setPosition(1673, 14);
		}
		else if (const auto weapon = dynamic_cast<HeartWeapon*>(player->get_weapon()))
		{
			selected_weapon_.setPosition(1748, 14);
		}
	}

	if(const auto level = dynamic_cast<LevelBase*>(subject))
	{
		if (level->waves_.size() > 0)
		{
			Wave* current_wave_ = level->waves_.front();
			if (current_wave_->get_delay() < 5)
			{
				if (!arrows_created_)
				{
					arrows_created_ = true;
					wave_size_ = current_wave_->objects_.size();
					for (int i = 0; i < wave_size_; ++i)
					{
						const sf::Vector2f enemy_pos = current_wave_->objects_[i]->
							getPosition();
						arrows[i].setPosition( Game::GAME_WIDTH - arrow_screen_offset_, enemy_pos.y );
					}
				}
				wave_incoming_ = true;
				blink_timer_ += delta_time;
				if (blink_timer_ > blink_time_)
				{
					should_draw_ = !should_draw_;
					blink_timer_ = 0;
				}
			}
			else
			{
				arrows_created_ = false;
				wave_incoming_ = false;
				should_draw_ = false;
			}
		}
	}
}
