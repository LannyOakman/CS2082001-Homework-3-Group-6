#include "OneDimHash.h"
OneDimHash::~OneDimHash() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		delete this->table[i];
	}

}
int OneDimHash::hashFunc(int val) {
	return val % MAX_SIZE;
}

int OneDimHash::insert(int val) {
	int collisions = 0;
	int index = hashFunc(val);

	int* new_val = new int(val);

	if (index >= MAX_SIZE) index -= MAX_SIZE;

	// loop  closes if spot is empty
	while (this->table[index] != nullptr && collisions < MAX_SIZE) {
		//loop back to neg index;
		if (index >= MAX_SIZE) index -= MAX_SIZE;

		index += 1;
		collisions += 1;

	}
	//check if all nodes have been searched
	if (collisions >= MAX_SIZE) {
		std::cout << "The value " <<val<<" cannot be inserted." << std::endl;
		return collisions;
	}

	this->table[index] = new_val;
	this->count += 1;
	std::cout << "NOTE: Value inserted after " << collisions << " collisions." << std::endl;
	return collisions+1;


}
//working
int OneDimHash::search(int val) {
	int collisions = 0;
	int index = hashFunc(val);

	//if (index >= MAX_SIZE) index -= MAX_SIZE;
	//(*(this->table[index]) != val && this->table[index]!=nullptr) && collisions < MAX_SIZE

	while (collisions < MAX_SIZE) {
		if (index >= MAX_SIZE) index -= MAX_SIZE;

		if (this->table[index] != nullptr) {
			//check if value matches
			if (*this->table[index] == val) break;
		}

		//std::cout << index << std::endl;


		index += 1;
		collisions += 1;
		//loop back to neg index;


	}

	if (collisions >= MAX_SIZE) {
		std::cout << "The value " << val << " cannot be found." << std::endl;
		return collisions;
	}

	std::cout << "The value " << val << " can be found." << std::endl;
	return collisions+1;

}

int OneDimHash::inTable(int start_index, int val) {
	int index = start_index;
	int collisions = 0;

	while (collisions < MAX_SIZE) {
		if (index >= MAX_SIZE) index -= MAX_SIZE;

		if (this->table[index] != nullptr) {
			//check if value matches
			if (*this->table[index] == val) break;
		}

		//std::cout << index << std::endl;


		index += 1;
		collisions += 1;
		//loop back to neg index;


	}

	if (collisions >= MAX_SIZE) {
		std::cout << "The value " << val<< " cannot be found." << std::endl;
		return (collisions+1) * -1;
	}

	if (*(this->table[index]) == val) {
		return index;
	}

	return (collisions+1) * -1;

}

int OneDimHash::remove(int val) {
	int repositions = 0;
	int collisions = 0;
	int index = hashFunc(val);

	if (index >= MAX_SIZE) index -= MAX_SIZE;
	// returns negative if not found;
	int search_result = inTable(index, val);

	if (search_result < 0) {
		std::cout << "The value " << val << " cannot be removed." << std::endl;
		return search_result * -1;
	}

	int current_index = search_result;
	//start removal
	delete this->table[current_index];
	this->table[current_index] = nullptr;
	this->count -= 1;


	int prev_index = current_index;
	current_index += 1;

	while (this->table[current_index] != nullptr) {
		if (hashFunc(*this->table[current_index]) == hashFunc(val)) {


			if (current_index >= MAX_SIZE) current_index -= MAX_SIZE;
			if (prev_index >= MAX_SIZE) prev_index -= MAX_SIZE;

			this->table[prev_index] = this->table[current_index];
			prev_index = current_index;
			current_index += 1;
			repositions += 1;
		}
		else break;
		
	}


	//finally turn current index to nullptr;
	//delete this->table[prev_index];
	if (this->table[prev_index] != nullptr) {
		this->table[prev_index] = nullptr;
	}

	//std::cout << *table[current_index] << std::endl;
	return repositions+1;

}

void OneDimHash::print() {
	//looping through all spots bc i want indexes
	//not printing nulls
	std::cout << "_____OCCUPIED_1D_TABLE_VALUES______________________________________" << std::endl;
	std::cout << "Item Count: " << count << std::endl;
	for (int i = 0; i < 500; i++) {
		if (this->table[i] != nullptr) {
			std::cout << "VALUE: " << *this->table[i] << " | INDEX: " << i << std::endl;
		}

	}
}