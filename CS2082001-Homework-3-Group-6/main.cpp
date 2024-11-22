/*
Test examples for using 2d hash table

Everything works I think. I just need to deal with making destructors.

Sometimes all of the search values are not found in the table. In that case just run it again to see it's implementation.
*/

#include "TwoDimHash.h"
#include "OneDimHash.h"

#include <string>

void big_line() {
	std::cout << "\n___________________________________________________\n";
}

int main() {
	TwoDimHash table;
	OneDimHash one_d;

	srand(time(0));

	//adds ints to table.
	for (int i = 0; i < 200; i++) {
		std::cout << table.insert(1 + (rand() % 1000));
		std::cout << one_d.insert(1 + (rand() % 1000));
	}
	big_line();

	//print table
	table.print();

	big_line();

	//search for value
	std::cout << table.search(22) << "\n";
	std::cout << table.search(52) << "\n";
	std::cout << table.search(105) << "\n";
	std::cout << table.search(905) << "\n";
	std::cout << table.search(32) << "\n";
	std::cout << table.search(92) << "\n";
	std::cout << table.search(185) << "\n";
	std::cout << table.search(995) << "\n";

	big_line();
	
	//remove value
	std::cout << table.remove(22) << "\n";
	std::cout << table.remove(52) << "\n";
	std::cout << table.remove(105) << "\n";
	std::cout << table.remove(905) << "\n";
	std::cout << table.remove(32) << "\n";
	std::cout << table.remove(92) << "\n";
	std::cout << table.remove(185) << "\n";
	std::cout << table.remove(995) << "\n";

	big_line();

	//see if anything changed from previous search.
	std::cout << table.search(22) << "\n";
	std::cout << table.search(52) << "\n";
	std::cout << table.search(105) << "\n";
	std::cout << table.search(905) << "\n";
	std::cout << table.search(32) << "\n";
	std::cout << table.search(92) << "\n";
	std::cout << table.search(185) << "\n";
	std::cout << table.search(995) << "\n";

	big_line();

	table.print();
	one_d.print();



	table.insert(4);
	table.insert(104);
	table.insert(204);
	table.insert(304);
	table.insert(404);

	table.print();

	table.remove(304);

	table.print();

	
}