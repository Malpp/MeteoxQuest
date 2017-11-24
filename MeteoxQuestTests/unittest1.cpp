#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MeteoxQuest/player.h"
#include "../MeteoxQuest/SFML-2.4.2/include/SFML/System/Vector2.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MeteoxQuestTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Player player_(sf::Vector2f(123,123), 0);
		}

	};
}