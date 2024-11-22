#include "pch.h"

#include "CppUnitTest.h"
#include "..\CS2082001-Homework-3-Group-6\OneDimHash.h"
#include "..\CS2082001-Homework-3-Group-6\OneDimHash.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OneDimHashTest
{
	TEST_CLASS(OneDimHashTest)
	{
	public:
		/* TestLinearProbbingInsertion
		* Set insertion of values with the same hash
		* EX: 1, 501, 1001 so that collison
		* then check to see that finding 1001 will take 2 collisions,
			3 tries
		*/
		TEST_METHOD(TestLinearProbbingInsertion)
		{
			OneDimHash table;
			table.insert(1);
			table.insert(501);
			Assert::AreEqual(table.insert(1001),3);
		}

		/*Testing search with linear probing: should take 4 trys to find 545
		*/
		TEST_METHOD(TestLinearProbbingSearch)
		{
			OneDimHash table;
			table.insert(45);
			table.insert(46);
			table.insert(47);
			table.insert(545);
			Assert::AreEqual(table.search(545), 4);
		}

		/*Getting worst case O(n) search from an item not present in this table
		* NOTE: Must travere whole table instead of stopping at nearest null value
		* due to collision insertion 
		* 
		*	EX:inserting: 1, 2, 101 to indexes: 0,1,2
		* 
		*	deleting 2 which would cause a gap between 1 and 101 that would 
		*	have a search for 101 return false after 2 checks due to the gap
		*/
		TEST_METHOD(Test_Not_Num_In_Table)
		{
			OneDimHash table;
			table.insert(45);
			table.insert(46);
			table.insert(47);
			table.insert(545);
			Assert::AreEqual(table.search(600), 500);
		}

		/*Removing num then making sure such for removed value is unsuccessful
		*/
		TEST_METHOD(Removal_Then_Search)
		{
			OneDimHash table;
			table.insert(46);
			table.insert(47);
			table.insert(545);
			table.insert(546);
			table.remove(46);
			Assert::AreEqual(table.search(46), 500);
		}

		/*Removing num the shifiting num's of same hash backwards IF and only IF said values
		* directly follow each other
		*/
		TEST_METHOD(Removal_Then_LinearProbbing_Reinserting) {
			OneDimHash table;
			table.insert(46);
			table.insert(546);
			table.insert(1046);
			table.insert(547);
			table.remove(46);
			Assert::AreEqual(table.search(1046), 2);
		}

		




	};
}
