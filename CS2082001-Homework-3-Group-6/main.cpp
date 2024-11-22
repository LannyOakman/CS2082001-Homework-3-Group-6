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
	
	int data_set [100];

	TwoDimHash table;

	OneDimHash oneDtable;
	//0 for 1d 1 for 2d
	int insert_attempts[2]{ 0 };
	int insert_attempts2[2]{ 0 };

	int removal_attempts[2]{ 0 };
	int search_attempts[2]{ 0 };

	
	
	


	srand(time(0));

	//adds ints to d.
	for (int i = 0; i < 100; i++) {
		data_set[i]= 1 + (rand() % 1000);
		
	}
	big_line();

	std::cout << "Insertion 1D table\n";

	for (int i = 0; i < 50; i++) {
		insert_attempts[0]+=oneDtable.insert(data_set[i]);
	}
	
	big_line();

	std::cout << "Insertion 2D table\n";

	for (int i = 0; i < 50; i++) {
		insert_attempts[1] += table.Insert(data_set[i]);
	}
	big_line();
	big_line();

	std::cout << "Insertion Results\n\n";

	std::cout << "\t1D Insertion completed within " <<insert_attempts[0]
		<< " attempts\n";

	std::cout << "\t2D Insertion completed within " << insert_attempts[1]
		<< " attempts\n";
	big_line();
	big_line();

	int removal_count = 0;
	for (int i = 0; i < 50; i++) {
		// check if values in dataset meet condition
		int num = data_set[i];
		if ( num % 7 == 0) {
			removal_count += 1;
			removal_attempts[0] += oneDtable.remove(num);
			removal_attempts[1] += table.Remove(num);

		}
	}
	big_line();
	big_line();

	std::cout << "Removal Results:\n\n";
	std::cout << "Items Removed: " << removal_count << std::endl;

	std::cout << "\t1D Removal completed within " << removal_attempts[0]
		<< " attempts\n";

	std::cout << "\t2D Removal completed within " << removal_attempts[1]
		<< " attempts\n";
	big_line();
	big_line();

	std::cout << "Insertion part 2 table\n";


	for (int i = 50; i < 100; i++) {
		insert_attempts2[1] += table.Insert(data_set[i]);
		insert_attempts2[0] += oneDtable.insert(data_set[i]);

	OneDimHash one_d;

	srand(time(0));

	//adds ints to table.
	for (int i = 0; i < 200; i++) {
		std::cout << table.insert(1 + (rand() % 1000));
		std::cout << one_d.insert(1 + (rand() % 1000));

	}
	big_line();
	big_line();

	std::cout << "Insertion Results Part 2\n\n";


	std::cout << "\t1D Insertion completed within " << insert_attempts2[0]
		<< " attempts\n";

	//print table
	table.print();


	std::cout << "\t2D Insertion completed within " << insert_attempts2[1]
		<< " attempts\n";
	big_line();
	big_line();

	int items_searched = 0;

	for (int i : data_set) {
		// check if values in dataset meet condition
		
		if (i % 9 == 0) {
			items_searched += 1;
			
			search_attempts[0] += oneDtable.search(i);
			search_attempts[1] += table.Search(i);
      
	//search for value
	std::cout << table.search(22) << "\n";
	std::cout << table.search(52) << "\n";
	std::cout << table.search(105) << "\n";
	std::cout << table.search(905) << "\n";
	std::cout << table.search(32) << "\n";
	std::cout << table.search(92) << "\n";
	std::cout << table.search(185) << "\n";
	std::cout << table.search(995) << "\n";

		}
	}
	big_line();
	big_line();
	

	std::cout << "Final Search\n\n";
	std::cout << "\t1D Search completed within " << search_attempts[0]
		<< " attempts\n";
 //remove value
	std::cout << table.remove(22) << "\n";
	std::cout << table.remove(52) << "\n";
	std::cout << table.remove(105) << "\n";
	std::cout << table.remove(905) << "\n";
	std::cout << table.remove(32) << "\n";
	std::cout << table.remove(92) << "\n";
	std::cout << table.remove(185) << "\n";
	std::cout << table.remove(995) << "\n";


	std::cout << "\t2D Search completed within " << search_attempts[1]
		<< " attempts\n";
	big_line();
	//We Could Display the Tables Here??????




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
	//Final Result Display
	std::cout << "\nFinal Results:\n\n";
	//Insertion
	std::cout << "   Insertion Results:\n";

	std::cout << "\t1D Insertion completed within " << insert_attempts[0]
		<< " attempts\n";

	std::cout << "\t2D Insertion completed within " << insert_attempts[1]
		<< " attempts\n";
	
	//Removal
	std::cout << "\n  Removal Results:\n";
	std::cout << "\tItems Removed: " << removal_count << std::endl;

	std::cout << "\t1D Removal completed within " << removal_attempts[0]
		<< " attempts\n";

	std::cout << "\t2D Removal completed within " << removal_attempts[1]
		<< " attempts\n";
	//Insertion part2
	std::cout << std::endl;
	std::cout << "   Insertion Results Part 2:\n";

	std::cout << "\t1D Insertion completed within " << insert_attempts2[0]
		<< " attempts\n";

	std::cout << "\t2D Insertion completed within " << insert_attempts2[1]
		<< " attempts\n";
	//Search
	std::cout << std::endl;
	std::cout << "   Search Results:\n";
	std::cout << "\t1D Search completed within " << search_attempts[0]
		<< " attempts\n";

	std::cout << "\t2D Search completed within " << search_attempts[1]
		<< " attempts\n";






	

	

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