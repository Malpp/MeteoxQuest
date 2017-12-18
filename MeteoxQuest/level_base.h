#pragma once
#include "stdafx.h"
#include "scene.h"
#include "player.h"
#include "wave.h"
#include "hud.h"
#include "deque.h"

class GameObject;

class LevelBase : public Scene, public Subject
{
	friend class Hud;
public:
	LevelBase(
		sf::RenderWindow* window,
		sf::Texture* texture,
		float scroll_speed);
	virtual ~LevelBase();
	void input() override;
	void update(float delta_time) override;
	void draw() override;
	virtual void manage_input(sf::Event event);
	void add_game_object(GameObject* projectile);
	void add_score( const int score_to_add );
	Player* get_player() const;
	void play_sound(sf::SoundBuffer* buffer);
	int get_combo() const;
private:
	void update_sounds();
	Player* player_;
	float scroll_speed_;
	sf::Sprite background_sprites_[2];
	std::vector<GameObject*> objects_;
	float fps_timer_;
	int fps_;
	Hud hud;
	Deque<sf::Sound> sound_queue_;
	int combo_;
	float combo_timer_;
	static const float combo_time_;
protected:
	unsigned int nbr_enemies_;
	bool load_level(const std::string path);
	sf::Vector2f background_size_;
	Deque<Wave*> waves_;

};
