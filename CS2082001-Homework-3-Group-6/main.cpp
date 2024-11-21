/*
Test examples for using 2d hash table

Everything works I think. I just need to deal with making destructors.

Sometimes all of the search values are not found in the table. In that case just run it again to see it's implementation.
*/

#include "TwoDimHash.h"
#include <string>

void big_line() {
	std::cout << "\n___________________________________________________\n";
}

int main() {
	TwoDimHash table;

	srand(time(0));

	//adds ints to table.
	for (int i = 0; i < 200; i++) {
		std::cout << table.Insert(1 + (rand() % 1000));
	}
	big_line();

	//print table
	table.Print();

	big_line();

	//search for value
	std::cout << table.Search(22) << "\n";
	std::cout << table.Search(52) << "\n";
	std::cout << table.Search(105) << "\n";
	std::cout << table.Search(905) << "\n";
	std::cout << table.Search(32) << "\n";
	std::cout << table.Search(92) << "\n";
	std::cout << table.Search(185) << "\n";
	std::cout << table.Search(995) << "\n";

	big_line();
	
	//remove value
	std::cout << table.Remove(22) << "\n";
	std::cout << table.Remove(52) << "\n";
	std::cout << table.Remove(105) << "\n";
	std::cout << table.Remove(905) << "\n";
	std::cout << table.Remove(32) << "\n";
	std::cout << table.Remove(92) << "\n";
	std::cout << table.Remove(185) << "\n";
	std::cout << table.Remove(995) << "\n";

	big_line();

	//see if anything changed from previous search.
	std::cout << table.Search(22) << "\n";
	std::cout << table.Search(52) << "\n";
	std::cout << table.Search(105) << "\n";
	std::cout << table.Search(905) << "\n";
	std::cout << table.Search(32) << "\n";
	std::cout << table.Search(92) << "\n";
	std::cout << table.Search(185) << "\n";
	std::cout << table.Search(995) << "\n";

	big_line();

	table.Print();

}