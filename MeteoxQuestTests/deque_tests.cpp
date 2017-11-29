#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MeteoxQuest/deque.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MeteoxQuestTests
{
	TEST_CLASS( DequeTests )
	{
	public:

		TEST_METHOD( DequeConstructorTest )
		{
			Deque<int> deque;
		}
		
		TEST_METHOD( DequePushBack1 )
		{
			
			Deque<int> deque;
			
			deque.push_back( 1 );
			int size = deque.size();
			Assert::AreEqual( 1, deque.size() );
			Assert::AreEqual( 1, deque.front() );
			Assert::AreEqual( 1, deque.back() );
		}
		
		TEST_METHOD( DequePushBack2 )
		{
			Deque<int> deque;

			deque.push_back( 1 );
			deque.push_back( 2 );
			Assert::AreEqual( 2, deque.size() );
			Assert::AreEqual( 1, deque.front() );
			Assert::AreEqual( 2, deque.back() );
		}

		TEST_METHOD( DequePushBack3 )
		{
			Deque<int> deque;

			deque.push_back( 1 );
			deque.push_back( 2 );
			deque.push_back( 3 );
			Assert::AreEqual( 3, deque.size() );
			Assert::AreEqual( 1, deque.front() );
			Assert::AreEqual( 3, deque.back() );
		}

		TEST_METHOD( DequePushFront1 )
		{
			Deque<int> deque;

			deque.push_front( 1 );
			Assert::AreEqual( 1, deque.size() );
			Assert::AreEqual( 1, deque.front() );
			Assert::AreEqual( 1, deque.back() );
		}

		TEST_METHOD( DequePushFront2 )
		{
			Deque<int> deque;

			deque.push_front( 1 );
			deque.push_front( 2 );
			Assert::AreEqual( 2, deque.size() );
			Assert::AreEqual( 2, deque.front() );
			Assert::AreEqual( 1, deque.back() );
		}

		TEST_METHOD( DequePushFront3 )
		{
			Deque<int> deque;

			deque.push_front( 1 );
			deque.push_front( 2 );
			deque.push_front( 3 );
			Assert::AreEqual( 3, deque.size() );
			Assert::AreEqual( 3, deque.front() );
			Assert::AreEqual( 1, deque.back() );
		}

		TEST_METHOD( DequePushFrontBack1 )
		{
			Deque<int> deque;

			deque.push_back( 2 );
			deque.push_front( 1 );
			Assert::AreEqual( 2, deque.size() );
			Assert::AreEqual( 1, deque.front() );
			Assert::AreEqual( 2, deque.back() );
		}

		TEST_METHOD( DequePushFrontBack2 )
		{
			Deque<int> deque;

			deque.push_back( 1 );
			deque.push_front( 2 );
			Assert::AreEqual( 2, deque.size() );
			Assert::AreEqual( 2, deque.front() );
			Assert::AreEqual( 1, deque.back() );
		}

		TEST_METHOD( DequePushFrontBack3 )
		{
			Deque<int> deque;

			deque.push_back( 1 );
			deque.push_front( 2 );
			deque.push_back( 1 );
			deque.push_front( 2 );
			deque.push_front( 2 );
			deque.push_front( 2 );
			deque.push_front( 8 );
			Assert::AreEqual( 7, deque.size() );
			Assert::AreEqual( 8, deque.front() );
			Assert::AreEqual( 1, deque.back() );
		}

		TEST_METHOD( DequePushFrontBack4 )
		{
			Deque<int> deque;

			for (int i = 0; i < 10; ++i)
			{
				deque.push_back( i );
			}

			for (int i = 0; i < 10; ++i)
			{
				deque.push_front( i );
			}
			Assert::AreEqual( 7, deque.size() );
			Assert::AreEqual( 8, deque.front() );
			Assert::AreEqual( 1, deque.back() );
		}
		
	};
}