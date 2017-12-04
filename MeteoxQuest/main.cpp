// SFML_Template.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Game.h"
#include "list.h"
#include <iostream>

int main()
{
	Game game;
	list<int> test;
	test.push_front(10);
	std::cout << test.front() << std::endl;
	test.push_back(20);
	std::cout << test.front() << std::endl;
	std::cout << test.back() << std::endl;
	list<int>::iterator i = test.begin();
	++i;
	test.insert(i, 15);
	
	game.run();
	return 0;
}
