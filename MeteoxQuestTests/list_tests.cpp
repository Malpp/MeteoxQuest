#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MeteoxQuest/list.h"
#include <iostream>

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

		TEST_METHOD(listCopyConstructorTest)
		{
			list<int> list1;
			list1.push_front(2);
			list1.push_back(3);
			list<int> list2(list1);
			Assert::AreEqual(2, list2.front());
			Assert::AreEqual(3, list2.back());
		}

		TEST_METHOD(listEqualOperatorTest)
		{
			list<int> list1;
			list1.push_front(2);
			list1.push_back(3);
			list<int> list2 = list1;
			Assert::AreEqual(2, list2.front());
			Assert::AreEqual(3, list2.back());
		}

		TEST_METHOD(listFront1)
		{
			list<int> list;
			
			list.push_back(1);
			Assert::AreEqual(1, list.front());
		}

		TEST_METHOD(listFront2)
		{
			list<int> list;

			list.push_front(3);
			list.push_back(1);

			Assert::AreEqual(3, list.front());
		}

		TEST_METHOD(listFront3)
		{
			list<int> list;

			list.push_front(3);
			list.push_front(2);
			list.push_back(1);

			Assert::AreEqual(2, list.front());
		}

		TEST_METHOD(listBack1)
		{
			list<int> list;

			list.push_back(1);
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listBack2)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(3);
			Assert::AreEqual(3, list.back());
		}

		TEST_METHOD(listBack3)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(3);
			list.push_front(2);
			list.push_back(4);
			Assert::AreEqual(4, list.back());
		}

		TEST_METHOD(listEmptyTrue)
		{
			list<int> list;

			Assert::IsTrue(list.empty());
		}

		TEST_METHOD(listEmptyFalse)
		{
			list<int> list;

			list.push_front(1);

			Assert::IsFalse(list.empty());
		}

		TEST_METHOD(listSize1)
		{
			list<int> list;

			Assert::AreEqual(0, (int)list.size());
		}

		TEST_METHOD(listSize2)
		{
			list<int> list;

			list.push_front(1);

			Assert::AreEqual(1, (int)list.size());
		}

		TEST_METHOD(listSize3)
		{
			list<int> list;

			list.push_front(1);
			list.push_back(1);
			Assert::AreEqual(2, (int)list.size());
		}

		TEST_METHOD(listSize4)
		{
			list<int> list;

			for (int i = 0; i < 10; ++i)
				list.push_front(1);
			Assert::AreEqual(10, (int)list.size());
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
			Assert::IsTrue(list.empty());
		}

		TEST_METHOD(listPopBack1)
		{
			list<int> list;

			list.push_back(1);
			list.pop_back();

			Assert::AreEqual(0, (int)list.size());
		}

		TEST_METHOD(listPopBack2)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(1);
			list.pop_back();
			Assert::AreEqual(1, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPopBack3)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			list.pop_back();
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(2, list.back());
		}

		TEST_METHOD(listPopBack4)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(2);
			list.pop_back();
			list.push_back(3);
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(3, list.back());
		}

		TEST_METHOD(listPopBack5)
		{
			list<int> list;

			list.push_back(1);
			list.pop_back();
			list.push_back(2);
			list.push_back(3);
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(3, list.back());
		}

		TEST_METHOD(listPopBack6)
		{
			list<int> list;

			list.push_front(1);
			list.pop_back();
			Assert::AreEqual(0, (int)list.size());
		}

		TEST_METHOD(listPopBack7)
		{
			list<int> list;

			 list.push_front(1);
			 list.push_front(2);
			 list.pop_back();
			Assert::AreEqual(1, (int)list.size());
			Assert::AreEqual(2,  list.front());
			Assert::AreEqual(2,  list.back());
		}

		TEST_METHOD(listPopBack8)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.pop_back();
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(3, list.front());
			Assert::AreEqual(2, list.back());
		}

		TEST_METHOD(listPopBack9)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			list.pop_back();
			list.push_back(124);
			list.push_front(3);
			list.pop_back();
			list.push_back(124);
			list.push_front(3);
			list.push_front(31);
			Assert::AreEqual(5, (int)list.size());
			Assert::AreEqual(31, list.front());
			Assert::AreEqual(124, list.back());
		}

		TEST_METHOD(listPopFront1)
		{
			list<int> list;

			list.push_back(1);
			list.pop_front();
			Assert::AreEqual(0, (int)list.size());
		}

		TEST_METHOD(listPopFront2)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(1);
			list.pop_front();
			Assert::AreEqual(1, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPopFront3)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			list.pop_front();
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(3, list.back());
		}

		TEST_METHOD(listPopFront4)
		{
			list<int> list;

			list.push_back(1);
			list.push_back(2);
			list.pop_front();
			list.push_back(3);
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(3, list.back());
		}

		TEST_METHOD(listPopFront5)
		{
			list<int> list;

			list.push_back(1);
			list.pop_front();
			list.push_back(2);
			list.push_back(3);
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(3, list.back());
		}

		TEST_METHOD(listPopFront6)
		{
			list<int> list;

			list.push_front(1);
			list.pop_front();
			Assert::AreEqual(0, (int)list.size());
		}

		TEST_METHOD(listPopFront7)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			list.pop_front();
			Assert::AreEqual(1, (int)list.size());
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPopFront8)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.pop_front();
			Assert::AreEqual(2, (int)list.size());
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(1, list.back());
		}

		TEST_METHOD(listPopFront9)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			list.pop_front();
			list.push_back(124);
			list.push_front(3);
			list.pop_front();
			list.push_back(124);
			list.push_front(3);
			list.push_front(31);
			Assert::AreEqual(5, (int)list.size());
			Assert::AreEqual(31, list.front());
			Assert::AreEqual(124, list.back());
		}

		TEST_METHOD(listErase1)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			list.push_front(3);

			list.erase(list.begin());
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(1, list.back());
			Assert::AreEqual(2, (int)list.size());
		}

		TEST_METHOD(listErase2)
		{
			list<int> list;

			list.push_front(1);
			list.push_front(2);
			list.push_front(3);

			list.erase(--list.end());
			Assert::AreEqual(3, list.front());
			Assert::AreEqual(2, list.back());
			Assert::AreEqual(2, (int)list.size());
		}

		TEST_METHOD(listErase3)
		{
			list<int> liste;

			liste.push_front(1);
			liste.push_front(2);
			liste.push_front(3);
			list<int>::iterator i = liste.begin();
			++i;
			liste.erase(i);
			Assert::AreEqual(3, liste.front());
			Assert::AreEqual(1, liste.back());
			Assert::AreEqual(2, (int)liste.size());
		}

		TEST_METHOD(listInsert1)
		{
			list<int> list;

			list.push_front(1);

			list.insert(list.begin(), 2);
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(1, list.back());
			Assert::AreEqual(2, (int)list.size());
		}

		TEST_METHOD(listInsert2)
		{
			list<int> list;

			list.push_front(1);

			list.insert(list.end(), 2);
			Assert::AreEqual(1, list.front());
			Assert::AreEqual(2, list.back());
			Assert::AreEqual(2, (int)list.size());
		}

		TEST_METHOD(listInsert3)
		{
			list<int> liste;

			liste.push_front(1);
			liste.push_back(2);
			list<int>::iterator i = liste.begin();
			++i;
			list<int>::iterator j = liste.insert(i, 3);
			Assert::AreEqual(1, liste.front());
			Assert::AreEqual(2, liste.back());
			Assert::AreEqual(3, *j);
			Assert::AreEqual(3, (int)liste.size());
		}

		TEST_METHOD(listBegin1)
		{
			list<int> list;

			Assert::IsTrue(list.begin() == nullptr);
		}

		TEST_METHOD(listBegin2)
		{
			list<int> liste;
			liste.push_front(1);
			list<int>::iterator i = liste.begin();
			Assert::AreEqual(1, *i);
		}

		TEST_METHOD(listBegin3)
		{
			list<int> liste;
			liste.push_front(1);
			list<int>::iterator i = liste.begin();
			liste.push_front(2);
			Assert::AreEqual(1, *i);
		}

		TEST_METHOD(listBegin4)
		{
			list<int> liste;
			liste.push_front(1);
			list<int>::iterator i = liste.begin();
			liste.push_front(2);
			--i;
			Assert::AreEqual(2, *i);
		}

		TEST_METHOD(listEnd1)
		{
			list<int> list;

			Assert::IsTrue(--list.end() == nullptr);
		}

		TEST_METHOD(listEnd2)
		{
			list<int> liste;
			liste.push_front(1);
			list<int>::iterator i = liste.end();
			--i;
			Assert::AreEqual(1, *i);
		}

		TEST_METHOD(listEnd3)
		{
			list<int> liste;
			liste.push_front(1);
			list<int>::iterator i = liste.end();
			liste.push_back(2);
			--i;
			Assert::AreEqual(2, *i);
		}
	};
}