#pragma once
#include "scene.h"

class Loading : public Scene
{
public:
	explicit Loading( sf::RenderWindow* window );
	void input() override;
	void update(float delta_time) override;
	void draw() override;
private:
	int current_element_;
	static const int elements_to_load_ = 7;
	sf::RectangleShape loading_bar_;
};
