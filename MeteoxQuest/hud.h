#pragma once
#include "iobserver.h"

class Hud : public IObserver
{
public:
	Hud();
	void draw(sf::RenderWindow* window) const;
	void notifier(Subject* subject) override;
private:
	int life_;
	unsigned int score_;
	sf::Text score_text_;
	sf::Text life_text_;
};
