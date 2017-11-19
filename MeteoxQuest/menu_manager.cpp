#include "stdafx.h"
#include "menu_manager.h"


MenuManager::~MenuManager()
{
	for (MenuElement* element : elements_)
	{
		delete element;
	}
}

void MenuManager::pre_input()
{
	for (MenuElement* element : elements_)
	{
		element->pre_input();
	}
}

void MenuManager::input( sf::Event& event, sf::RenderWindow* window )
{

	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Tab:
			if (event.key.shift)
				back();
			else
				next();
			break;
		}
	}

	if (event.type == sf::Event::MouseButtonReleased)
	{
		MenuElement::focused_element_ = nullptr;
	}

	if (event.type == sf::Event::LostFocus)
	{
		MenuElement::focused_element_ = nullptr;
	}

	for (MenuElement* element : elements_)
	{
		element->input( event, window );
	}
}

void MenuManager::update( float delta_time )
{
	for (MenuElement* element : elements_)
	{
		element->update( delta_time );
	}
}

void MenuManager::draw( sf::RenderWindow* window )
{
	for (MenuElement* element : elements_)
	{
		element->draw( window );
	}
}

void MenuManager::next()
{
	if (elements_.size() > 0)
	{
		int current_focus = get_current_focued();
		int init_focus_position = current_focus;
		if (current_focus >= 0) //If an element IS focused
		{
			fix_current_focus( &(++current_focus) );
			while(current_focus != init_focus_position)
			{
				if(elements_[current_focus]->is_focusable())
				{
					MenuElement::focused_element_ = elements_[current_focus];
					break;
				}
				fix_current_focus(&(++current_focus));
			}
		}
		else
		{
			for (MenuElement* element : elements_)
			{
				if (element->is_focusable())
				{
					MenuElement::focused_element_ = element;
					break;
				}
			}
		}
	}
}

void MenuManager::back()
{
	int current_focus = get_current_focued();
	if (elements_.size() > 0)
	{
		int current_focus = get_current_focued();
		int init_focus_position = current_focus;
		if (current_focus >= 0) //If an element IS focused
		{
			fix_current_focus(&(--current_focus));
			while (current_focus != init_focus_position)
			{
				if (elements_[current_focus]->is_focusable())
				{
					MenuElement::focused_element_ = elements_[current_focus];
					break;
				}
				fix_current_focus(&(--current_focus));
			}
		}
		else
		{
			for (unsigned i = elements_.size(); i --> 0; )
			{
				if (elements_[i]->is_focusable())
				{
					MenuElement::focused_element_ = elements_[i];
					break;
				}
			}
		}
	}
}

void MenuManager::add_to_menu( MenuElement* to_add )
{
	elements_.push_back( to_add );
}

int MenuManager::get_current_focued()
{
	for (int i = 0; i < elements_.size(); ++i)
	{
		if (MenuElement::focused_element_ == elements_[i])
		{
			return i;
		}
	}
	return -1;
}

void MenuManager::fix_current_focus( int* current_idx ) const
{
	int vec_size = elements_.size();
	if (*current_idx >= vec_size)
	{
		*current_idx = 0;
	}

	if (*current_idx < 0)
	{
		*current_idx = vec_size - 1;
	}
}
