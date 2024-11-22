#include "pch.h"
#include "CppUnitTest.h"
#include "../CS2082001-Homework-3-Group-6/TwoDimHash.cpp"
#include "../CS2082001-Homework-3-Group-6/TwoDimHash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TwoDimHashTest
{
	TEST_CLASS(TwoDimHashTest)
	{
	public:
		//Testing typical insertion.
		TEST_METHOD(testInsertion)
		{
			TwoDimHash table;
			table.insert(1);
			table.insert(101);
			table.insert(201);
			table.insert(301);
			Assert::AreEqual(table.insert(401), 5);
		}

		//testing insertion of a full row.
		TEST_METHOD(testInvalidInsertion)
		{
			TwoDimHash table;
			table.insert(1);
			table.insert(101);
			table.insert(201);
			table.insert(301);
			table.insert(401);
			table.insert(501);
			Assert::AreEqual(table.insert(601), 5);
		}

		//testing normal removal
		TEST_METHOD(testValidRemoval)
		{
			TwoDimHash table;
			table.insert(1);
			table.insert(101);
			Assert::AreEqual(table.remove(101), 2);
		}

		//testing invalid removal (int DNE in table)
		TEST_METHOD(testInvalidRemoval)
		{
			TwoDimHash table;
			table.insert(1);
			table.insert(101);
			Assert::AreEqual(table.remove(201), 3);
		}

		//testing insert after items are deleting to ensure numbers were shifted downwards.
		// instead of :
		// |101|0|0|0|501|
		// it should be:
		// |101|501|0|0|0|
		TEST_METHOD(testRemovalInsertGap)
		{
			TwoDimHash table;

			table.insert(101);
			table.insert(201);
			table.insert(301);
			table.insert(401);
			table.insert(501);

			table.remove(201);
			table.remove(301);
			table.remove(401);

			Assert::AreEqual(table.insert(901), 3);
		}

		//testing normal search
		TEST_METHOD(testValidSearch)
		{
			TwoDimHash table;
			table.insert(1);
			table.insert(101);
			table.insert(201);
			Assert::AreEqual(table.search(201), 3);
		}

		//testing invalid search (item being searched for DNE)
		TEST_METHOD(testInvalidSearch)
		{
			TwoDimHash table;
			table.insert(1);
			table.insert(101);
			table.insert(201);
			Assert::AreEqual(table.search(301), 4);
		}
	};
}
