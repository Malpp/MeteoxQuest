#pragma once
#include "stdafx.h"
#include "non_character.h"

class Projectile : public NonCharacter
{
public:
	Projectile(
		const sf::Vector2f& pos,
		float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		int no_frames,
		int no_states,
		float frame_delay,
		const sf::Vector2f& direction,
		GameType type,
		Color color,
		const float movespeed);
	Projectile(
		const sf::Vector2f& pos,
		float angle,
		sf::Texture* texture,
		const sf::Vector2f& size,
		int no_frames,
		int no_states,
		float frame_delay,
		const sf::Vector2f& direction,
		GameType type,
		Color color,
		const float movespeed,
		const float damage);
	void on_death(LevelBase* level) override;
protected:
	void handle_collision(GameObject* other, LevelBase* level) override;
	static const int base_damage_ = 1;
	static const int base_life_ = 1;
};
