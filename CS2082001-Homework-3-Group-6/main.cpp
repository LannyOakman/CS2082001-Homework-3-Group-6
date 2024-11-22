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

	
	
	

	//seeding random
	srand(time(0));

	//adds ints to data set.
	for (int i = 0; i < 100; i++) {
		data_set[i]= 1 + (rand() % 1000);
		
	}
	big_line();

	/*
	*
	*
	*
	*<-----------Initial Insertion--------------------------->
	*
	*
	*/

	std::cout << "Insertion 1D table\n";

	for (int i = 0; i < 50; i++) {
		insert_attempts[0]+=oneDtable.insert(data_set[i]);
	}
	
	big_line();

	std::cout << "Insertion 2D table\n";

	for (int i = 0; i < 50; i++) {
		insert_attempts[1] += table.insert(data_set[i]);
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


	/*
	*
	*
	*
	<-----------Selective Removal-------------------->
	*
	*
	*/

	int removal_count = 0;
	for (int i = 0; i < 50; i++) {
		// check if values in dataset meet condition
		int num = data_set[i];
		if ( num % 7 == 0) {
			removal_count += 1;
			removal_attempts[0] += oneDtable.remove(num);
			removal_attempts[1] += table.remove(num);

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



	/*
	*
	*
	*
	*<-----------Second Insertion--------------------------->
	*
	*
	*/
	std::cout << "Insertion part 2 table\n";


	for (int i = 50; i < 100; i++) {
		insert_attempts2[1] += table.insert(data_set[i]);
		insert_attempts2[0] += oneDtable.insert(data_set[i]);
	}

	big_line();
	big_line();

	std::cout << "Insertion Results Part 2\n\n";


	std::cout << "\t1D Insertion completed within " << insert_attempts2[0]
		<< " attempts\n";


	std::cout << "\t2D Insertion completed within " << insert_attempts2[1]
		<< " attempts\n";
	big_line();
	big_line();



	/*
	*
	*
	*
	*<-----------Search Operation--------------------------->
	*
	*
	*/

	int items_searched = 0;

	for (int i : data_set) {
		// check if values in dataset meet condition
		
		if (i % 9 == 0) {
			items_searched += 1;
			
			search_attempts[0] += oneDtable.search(i);
			search_attempts[1] += table.search(i);
		}
	}
	big_line();
	big_line();
	

	std::cout << "Final Search\n\n";
	std::cout << "\t1D Search completed within " << search_attempts[0]
		<< " attempts\n";


	std::cout << "\t2D Search completed within " << search_attempts[1]
		<< " attempts\n";
	big_line();
	//We Could Display the Tables Here??????
	
	oneDtable.print();

	big_line();

	table.print();

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
}