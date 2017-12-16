#pragma once
#include "iobserver.h"

class Hud : public IObserver
{
public:
	Hud();
	void draw(sf::RenderWindow* window) const;
	void notifier(Subject* subject, float delta_time) override;
	static sf::Texture* player_icon_texture_;
	static sf::Texture* heart_icon_texture_;
	static sf::Texture* mario_icon_texture_;
	//static sf::Texture* roller_coaster_icon_texture_;
	static sf::Texture* incoming_warning_;
	static sf::Texture* incoming_arrow_;
private:
	static const int number_of_arrows_ = 50;
	float arrow_screen_offset_;
	sf::Sprite arrows[number_of_arrows_];
	int life_;
	unsigned int score_;
	sf::CircleShape selected_weapon_;
	sf::Sprite player_icon_;
	sf::Sprite heart_weapon_icon_;
	sf::Sprite mario_weapon_icon_;
	//sf::Sprite roller_coaster_weapon_icon_;
	sf::Sprite warning_sprite_;
	sf::Text score_text_;
	sf::Text life_text_;
	static const float blink_time_;
	float blink_timer_;
	bool should_draw_;
	bool wave_incoming_;
	int wave_size_;
	bool arrows_created_;
	sf::Text shield_hp_;
	sf::Text no_shields_;
};
