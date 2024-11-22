#include "pch.h"
#include "CppUnitTest.h"
#include "../CS2082001-Homework-3-Group-6/TwoDimHash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TwoDimHashTest
{
	TEST_CLASS(TwoDimHashTest)
	{
	public:
		
		TEST_METHOD(testInsertion)
		{
			TwoDimHash table;
			table.insert(1);
			table.insert(101);
			Assert::AreEqual(table.insert(201), 3);
		}
	};
}
