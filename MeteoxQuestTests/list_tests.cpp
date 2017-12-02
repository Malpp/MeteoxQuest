#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MeteoxQuest/list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MeteoxQuestTests
{
	TEST_CLASS(ListTests)
	{
	public:
		TEST_METHOD(listConstructorTest)
		{
			list<int> list;
		}

		TEST_METHOD(listPushBack1)
		{
			list<int> list;

			list.push_back(1);
			int size = list.size();
			Assert::AreEqual(1, size);
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPushBack2)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(2);
			int size = list.size();
			Assert::AreEqual(2, size);
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(2, list.back());
		}

		TEST_METHOD(listPushBack3)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			int size = list.size();
			Assert::AreEqual(3, size);
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(3, list.back());
		}
	};
}