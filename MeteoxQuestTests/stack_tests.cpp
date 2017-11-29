#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MeteoxQuest/stack.h"
#include <stack>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MeteoxQuestTests
{
	TEST_CLASS( StackTests )
	{
	public:

		TEST_METHOD( StackConstructorTest )
		{
			Stack<int> stack;
			Assert::AreEqual( 0, static_cast<int>(stack.size()) );
		}

		TEST_METHOD( StackPush1 )
		{
			Stack<int> stack;
			stack.push( 1 );
			Assert::AreEqual( 1, stack.top() );
			Assert::AreEqual( 1, static_cast<int>(stack.size()) );
		}

		TEST_METHOD( StackPush2 )
		{
			Stack<int> stack;
			stack.push( 1 );
			stack.push( 10 );
			Assert::AreEqual( 10, stack.top() );
			Assert::AreEqual( 2, static_cast<int>(stack.size()) );
		}

		TEST_METHOD( StackPush3 )
		{
			Stack<int> stack;
			stack.push( 1 );
			stack.push( 1012312312 );
			stack.push( -1012312312 );
			stack.push( 1012312312 );
			stack.push( 1 );
			Assert::AreEqual( 1, stack.top() );
			Assert::AreEqual( 5, static_cast<int>(stack.size()) );
		}

		TEST_METHOD( StackPop1 )
		{
			Stack<int> stack;
			stack.push( 1 );
			stack.pop();
			Assert::AreEqual( 0, static_cast<int>(stack.size()) );
		}

		TEST_METHOD( StackPop2 )
		{
			Stack<int> stack;
			stack.push( 1 );
			stack.push( 2 );
			stack.pop();
			Assert::AreEqual( 1, static_cast<int>(stack.size()) );
			Assert::AreEqual( 1, stack.top() );
		}

		TEST_METHOD( StackPop3 )
		{
			Stack<int> stack;
			stack.push( 1 );
			stack.push( 2 );
			stack.pop();
			stack.push( 3 );
			stack.push( 4 );
			stack.pop();
			stack.push( 5 );
			stack.push( 6 );
			stack.pop();
			Assert::AreEqual( 3, static_cast<int>(stack.size()) );
			Assert::AreEqual( 5, stack.top() );
		}

		TEST_METHOD( StackSwap )
		{
			Stack<int> stack1;
			Stack<int> stack2;
			stack1.push( 1 );
			stack2.push( 2 );
			stack1.swap( stack2 );

			Assert::AreEqual( 1, static_cast<int>(stack1.size()) );
			Assert::AreEqual( 2, stack1.top() );

			Assert::AreEqual( 1, static_cast<int>(stack2.size()) );
			Assert::AreEqual( 1, stack2.top() );
		}

		TEST_METHOD( StackEqualBigger )
		{
			Stack<int> stack1;
			Stack<int> stack2;

			for (int i = 0; i < 10; ++i)
			{
				stack1.push( i + 1 );
			}

			stack1 = stack2;

			Assert::AreEqual( stack2.size(), stack1.size() );
		}

		TEST_METHOD( StackEqualSame )
		{
			Stack<int> stack1;
			Stack<int> stack2;

			for (int i = 0; i < 10; ++i)
			{
				stack1.push( i + 1 );
				stack2.push( i );
			}

			stack1 = stack2;

			Assert::AreEqual( stack2.top(), stack1.top() );
			Assert::AreEqual( stack2.size(), stack1.size() );
		}

		TEST_METHOD( StackEqualSmaller )
		{
			Stack<int> stack1;
			Stack<int> stack2;

			for (int i = 0; i < 10; ++i)
			{
				stack2.push( i + 1 );
			}

			stack1 = stack2;

			Assert::AreEqual( stack2.top(), stack1.top() );
			Assert::AreEqual( stack2.size(), stack1.size() );
		}

	};
}