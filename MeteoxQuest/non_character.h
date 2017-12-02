#pragma once
#include "game_object.h"

class NonCharacter : public GameObject
{
public:
	NonCharacter(const sf::Vector2f& pos,
				const float angle,
				sf::Texture* texture,
				const sf::Vector2f& size,
				const int no_frames,
				const int no_states,
				const float frame_delay,
				const int life,
				const Color color,
				const int damage,
				const GameType type);
	void update(const float delta_time, LevelBase* level) override;
protected:
	bool is_at_edge() override;
	void handle_edge() override;
	sf::Vector2f direction_;
};
