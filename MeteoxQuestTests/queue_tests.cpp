#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MeteoxQuest/queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MeteoxQuestTests
{		
	TEST_CLASS(QueueTests)
	{
	public:
		
		TEST_METHOD( CircularConstructorTest )
		{
			Queue<int> c_queue_1;
		}

		TEST_METHOD( CircularPush1 )
		{
			Queue<int> c_queue_1;
			c_queue_1.push( 1 );
			Assert::AreEqual( 1, c_queue_1.front() );
			Assert::AreEqual( 1, c_queue_1.back() );
		}

		TEST_METHOD( CircularPush2 )
		{
			Queue<int> c_queue_1;
			c_queue_1.push( 1 );
			c_queue_1.push( 2 );
			Assert::AreEqual( 1, c_queue_1.front() );
			Assert::AreEqual( 2, c_queue_1.back() );
		}

		TEST_METHOD( CircularPush3 )
		{
			Queue<int> c_queue_1;
			c_queue_1.push( 1 );
			c_queue_1.push( 2 );
			c_queue_1.push( 3 );
			Assert::AreEqual( 1, c_queue_1.front() );
			Assert::AreEqual( 3, c_queue_1.back() );
		}

		TEST_METHOD( CircularPop1 )
		{
			Queue<int> c_queue_1;
			c_queue_1.push( 1 );
			c_queue_1.pop();
			Assert::AreEqual( 0, static_cast<int>(c_queue_1.size()) );
		}

		TEST_METHOD( CircularPop2 )
		{
			Queue<int> c_queue_1;
			c_queue_1.push( 1 );
			c_queue_1.push( 1 );
			c_queue_1.pop();
			Assert::AreEqual( 1, static_cast<int>(c_queue_1.size()) );
		}

		TEST_METHOD( CircularSwap1 )
		{
			Queue<int> c_queue_1;
			Queue<int> c_queue_2;

			for (int i = 0; i < 10; ++i)
			{
				c_queue_1.push( i + 1 );
			}

			c_queue_1.swap( c_queue_2 );

			Assert::AreEqual( 0, static_cast<int>(c_queue_1.size()) );
			Assert::AreEqual( 10, static_cast<int>(c_queue_2.size()) );
		}

		TEST_METHOD( CircularEqualBigger )
		{
			Queue<int> c_queue_1;
			Queue<int> c_queue_2;

			for (int i = 0; i < 10; ++i)
			{
				c_queue_1.push( i + 1 );
			}

			c_queue_1 = c_queue_2;

			Assert::AreEqual( c_queue_2.size(), c_queue_1.size() );
		}

		TEST_METHOD( CircularEqualSame )
		{
			Queue<int> c_queue_1;
			Queue<int> c_queue_2;

			for (int i = 0; i < 10; ++i)
			{
				c_queue_1.push( i + 1 );
				c_queue_2.push( i );
			}

			c_queue_1 = c_queue_2;

			Assert::AreEqual( c_queue_2.front(), c_queue_1.front() );
			Assert::AreEqual( c_queue_2.back(), c_queue_1.back() );
			Assert::AreEqual( c_queue_2.size(), c_queue_1.size() );
		}

		TEST_METHOD( CircularEqualSmaller )
		{
			Queue<int> c_queue_1;
			Queue<int> c_queue_2;

			for (int i = 0; i < 10; ++i)
			{
				c_queue_2.push( i + 1 );
			}

			c_queue_1 = c_queue_2;

			Assert::AreEqual( c_queue_2.front(), c_queue_1.front() );
			Assert::AreEqual( c_queue_2.back(), c_queue_1.back() );
			Assert::AreEqual( c_queue_2.size(), c_queue_1.size() );
		}

	};
}