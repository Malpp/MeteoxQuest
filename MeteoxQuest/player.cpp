#include "stdafx.h"
#include "player.h"
#include "level_base.h"
#include "Game.h"
#include "heart_weapon.h"
#include "projectile.h"

sf::Texture* Player::texture_ = Game::resource_handler_.add_texture(
	"player.png");
const sf::Vector2f Player::size_ = sf::Vector2f(140, 80);
const float Player::movespeed_ = 600;
const float Player::frame_delay_ = 0.1f;

unsigned Player::get_score() const
{
	return score_;
}

void Player::add_score(const int score_to_add)
{
	score_ += score_to_add;
}

int Player::get_life() const
{
	return life_;
}

Player::Player(const sf::Vector2f& pos, const float angle)
	: Character(pos,
				angle,
				texture_,
				size_,
				no_frames_,
				COUNT,
				frame_delay_,
				movespeed_,
				base_life_,
				NONE,
				base_damage_,
				PLAYER),
	Subject()
{
	weapon_ = new HeartWeapon;
	score_ = 0;
}

void Player::update(const float delta_time, LevelBase* level)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		up();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		left();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		down();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		right();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		fire(level);
	if (velocity_.x == 0 && velocity_.y == 0)
		state_ = IDLE;
	Character::update(delta_time, level);
	notify_all_observers();
}

void Player::up()
{
	state_ = UP;
	Character::up();
}

void Player::down()
{
	state_ = DOWN;
	Character::down();
}

void Player::left()
{
	state_ = LEFT;
	Character::left();
}

void Player::right()
{
	state_ = RIGHT;
	Character::right();
}

void Player::on_death(LevelBase* level)
{
}

void Player::handle_collision(GameObject* other, LevelBase* level)
{
	if (dynamic_cast<Projectile*>(other) && dynamic_cast<Projectile*>(other)->get_type() == Projectile::ENEMY)
	{
		//take_damage( other );
	}

	if (dynamic_cast<Enemy*>(other))
	{
		//despawn();
	}
}
