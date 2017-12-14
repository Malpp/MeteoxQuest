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
			Assert::AreEqual(1, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPushBack2)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(2);
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(2, list.back());
		}

		TEST_METHOD(listPushBack3)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			Assert::AreEqual(3, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(3, list.back());
		}

		TEST_METHOD(listPushFront1)
		{
			list<int> list;

			list.push_front(1);
			Assert::AreEqual(1, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPushFront2)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPushFront3)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			Assert::AreEqual(3, (int)list.size());
			Assert::AreEqual(3, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPushFrontBack1)
		{
			list<int> list;

			list.push_back(2);
			list.push_front(1);
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(2, list.back());
		}

		TEST_METHOD(listPushFrontBack2)
		{
			list<int> list;

			list.push_back(1);
			list.push_front(2);
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPushFrontBack3)
		{
			list<int> list;

			list.push_back(1);
			list.push_front(2);
			list.push_back(1);
			list.push_front(2);
			list.push_front(2);
			list.push_front(2);
			list.push_front(8);
			Assert::AreEqual(7, (int)list.size());
			Assert::AreEqual(8, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPushFrontBack4)
		{
			list<int> list;

			for (int i = 0; i < 11; ++i)
			{
				list.push_back(i);
			}

			for (int i = 0; i < 10; ++i)
			{
				list.push_front(i);
			}
			Assert::AreEqual(21, (int)list.size());
			Assert::AreEqual(9, list.front());
			Assert::AreEqual(10, list.back());
		}

		TEST_METHOD(listClearTest)
		{
			list<int> list;

			for (int i = 0; i < 10; ++i)
			{
				list.push_front(10);
			}

			list.clear();
			Assert::AreEqual(0, (int)list.size());
		}
	};
}