#include "stdafx.h"
#include "menu_element.h"
#include "Game.h"

MenuElement* MenuElement::focused_element_ = nullptr;
sf::Color MenuElement::default_color_ = sf::Color( 204, 204, 204 );
sf::Color MenuElement::hover_color_ = sf::Color( 170, 170, 170 );
sf::Color MenuElement::focus_color_ = sf::Color( 28, 98, 185 );

MenuElement::MenuElement( sf::Vector2f& pos, sf::Vector2f& size, bool is_focusable )
{
	pos_ = pos;
	size_ = size;
	click_box_ = sf::FloatRect( pos.x, pos.y, size.x, size.y );
	is_hovering_ = false;
	is_focusable_ = is_focusable;
	is_active_ = false;
}

void MenuElement::update( float delta_time )
{

}

void MenuElement::input( sf::Event& event, sf::RenderWindow* window )
{
	const sf::Vector2f mouse_pos = window->mapPixelToCoords( sf::Mouse::getPosition( *window ) );
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		if (is_focusable_ && is_hovering_)
			focused_element_ = this;
		break;
	case sf::Event::MouseMoved:
		is_hovering_ = click_box_.contains( mouse_pos );
		break;
	}
	handle_input( event, window );
}

void MenuElement::pre_input()
{
	//Not active at the start of input, will be active during other inputs
	is_active_ = false;
}

bool MenuElement::get_active() const
{
	return is_active_;
}

bool MenuElement::is_focusable() const
{
	return is_focusable_;
}
