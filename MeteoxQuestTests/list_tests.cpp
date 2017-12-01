#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MeteoxQuest/list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MeteoxQuestTests
{
	TEST_CLASS(ListTests)
	{
	public:
		TEST_METHOD(DequeConstructorTest)
		{
			list<int> list;
		}
	};
}