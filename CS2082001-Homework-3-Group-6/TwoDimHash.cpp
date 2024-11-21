#include "TwoDimHash.h"

TwoDimHash::TwoDimHash() {
	//table declared in .h file.
}

TwoDimHash::~TwoDimHash() {
}

int TwoDimHash::Insert(int val) {
	int index = Hash(val);

	for (int i = 0; i < COL; i++) {
		if (!this->arr[index][i]) {
			arr[index][i] = val;
			return i + 1;
		}
		if (i == COL - 1) {
			std::cout << "The value " << val << " cannot be inserted.\n";
			return i + 1;
		}
	}

}

int TwoDimHash::Search(int val) {
	int index = Hash(val);

	for (int i = 0; i < COL; i++) {
		if (this->arr[index][i] == val) {
			std::cout << "The value " << val << " can be found.\n";
			return i + 1;
		}
		if (i == COL - 1 || !this->arr[index][i]) {
			std::cout << "The value " << val << " cannot be found.\n";
			return i + 1;
		}
	}

}

int TwoDimHash::Remove(int val) {

	int index = Hash(val);

	for (int i = 0; i < COL; i++) {
		if (this->arr[index][i] == val) {
			this->arr[index][i] = 0;
			std::cout << "The value " << val << " was removed.\n";
			return i + 1;
		}
		if (i == COL - 1) {
			std::cout << "The value " << val << " cannot be removed.\n";
			return i + 1;
		}
	}

}

void TwoDimHash::Print() {
	std::cout << "2D Hash Table (100x5)\n";
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//if (this->arr[i][j] == 0) break;
			std::cout << this->arr[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

int TwoDimHash::Hash(int val) {
	return val % 100;
}