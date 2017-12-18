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
	: arrow_screen_offset_(incoming_arrow_->getSize().y * 0.5f)
	, life_(0)
	, score_(0)
	, selected_weapon_(26)
	, warning_sprite_(*incoming_warning_)
	, score_text_("0", Game::font, 50)
	, life_text_("", Game::font)
	, blink_timer_(0)
	, should_draw_(false)
	, wave_incoming_(false)
	, wave_size_(0)
	, arrows_created_(false)
	, shield_hp_("", Game::font)
	, no_shields_("", Game::font)
	, ammo_text_("", Game::font)
	, ammo_should_draw_(false)
	, combo_text_("", Game::font)
{
	player_icon_.setPosition(10, 10);
	player_icon_.setTexture(*player_icon_texture_);
	heart_weapon_icon_.setTexture(*heart_icon_texture_);
	heart_weapon_icon_.setPosition(1600, 20);
	mario_weapon_icon_.setTexture(*mario_icon_texture_);
	mario_weapon_icon_.setPosition(1675, 20);
	center_text(score_text_);
	score_text_.setPosition(Game::GAME_WIDTH * 0.5f, 40);
	center_text(combo_text_);
	combo_text_.setPosition(Game::GAME_WIDTH * 0.5f, 85);
	life_text_.setPosition(95, 10);
	selected_weapon_.setFillColor(sf::Color::Transparent);
	selected_weapon_.setOutlineColor(sf::Color::White);
	selected_weapon_.setOutlineThickness(5);
	shield_hp_.setPosition(10, Game::GAME_HEIGHT - 80);
	no_shields_.setPosition(10, Game::GAME_HEIGHT - 40);
	center_text(ammo_text_);
	ammo_text_.setPosition(1675, 100);

	for(int i = 0; i < number_of_arrows_; ++i)
	{
		arrows[i].setTexture(*incoming_arrow_);
		arrows[i].setOrigin(
			static_cast<sf::Vector2f>(incoming_arrow_->getSize()) * 0.5f);
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
	window->draw(shield_hp_);
	window->draw(no_shields_);
	if(ammo_should_draw_)
		window->draw(ammo_text_);
	window->draw(combo_text_);
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
		if(player->shield_exists())
		{
			std::stringstream shield_hp_stream;
			shield_hp_stream << player->get_shield()->get_life();
			shield_hp_.setString(shield_hp_stream.str());
			shield_hp_.setFillColor(player->get_shield()->getColor());
		}
		else
		{
			shield_hp_.setString("");
		}

		std::stringstream no_shields_stream;
		no_shields_stream << player->get_no_shields();
		no_shields_.setString(no_shields_stream.str());

		std::stringstream score_stream;
		score_stream << player->get_score();
		score_text_.setString(score_stream.str());
		center_text(score_text_);

		const int ammo = player->get_weapon()->get_ammo();
		if(ammo > -1)
		{
			ammo_should_draw_ = true;
			std::stringstream ammo_stream;
			ammo_stream << ammo;
			ammo_text_.setString(ammo_stream.str());
			center_text(ammo_text_);
		}
		else
		{
			ammo_should_draw_ = false;
		}

		std::stringstream life_stream;
		const int life = player->get_life();
		life_stream << life;
		life_text_.setString("x " + life_stream.str());

		if(const auto weapon = dynamic_cast<HeartWeapon*>(player->get_weapon()))
		{
			selected_weapon_.setPosition(1598, 14);
		}
		else if(const auto weapon = dynamic_cast<MarioWeapon*>(player->
			get_weapon()))
		{
			selected_weapon_.setPosition(1673, 14);
		}
		else if(const auto weapon = dynamic_cast<HeartWeapon*>(player->
			get_weapon()))
		{
			selected_weapon_.setPosition(1748, 14);
		}
	}

	if(const auto level = dynamic_cast<LevelBase*>(subject))
	{
		if(level->waves_.size() > 0)
		{
			Wave* current_wave_ = level->waves_.front();
			if(current_wave_->get_delay() < 5)
			{
				if(!arrows_created_)
				{
					arrows_created_ = true;
					wave_size_ = current_wave_->objects_.size();
					for(int i = 0; i < wave_size_; ++i)
					{
						const sf::Vector2f enemy_pos = current_wave_->objects_[i]->
								getPosition();
						arrows[i].setPosition(Game::GAME_WIDTH - arrow_screen_offset_,
						                      enemy_pos.y);
					}
				}
				wave_incoming_ = true;
				blink_timer_ += delta_time;
				if(blink_timer_ > blink_time_)
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

		std::stringstream combo_stream;
		combo_stream << "x" << level->get_combo();
		combo_text_.setString(combo_stream.str());
		center_text(combo_text_);
		color_text_combo(combo_text_, level->get_combo());
	}
}

void Hud::center_text(sf::Text& text)
{
	const int char_size = text.getCharacterSize();
	text.setOrigin(char_size * text.getString().getSize() * 0.5f,
	               char_size * 0.5f);
}

void Hud::color_text_combo(sf::Text& text, int combo)
{
	combo = sqrtf(combo) - 1;
	const sf::Color color(std::min(15, combo) * 17,
	                      (15 - std::min(15, combo)) * 17,
	                      0);
	text.setFillColor(color);
}
