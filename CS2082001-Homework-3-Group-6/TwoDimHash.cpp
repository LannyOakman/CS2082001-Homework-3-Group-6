#include "TwoDimHash.h"

TwoDimHash::TwoDimHash() {
	//table declared in .h file.
}

TwoDimHash::~TwoDimHash() {
}

int TwoDimHash::insert(int val) {
	int index = hash(val);

	for (int i = 0; i < COL; i++) {
		if (!this->arr[index][i]) {
			arr[index][i] = val;

			std::cout << "2D_NOTE: Value " << val << " inserted after " << i << " collisions.\n";
			return i + 1;
		}
		if (i == COL - 1) {
			std::cout << "2D_NOTE: Value " << val << " cannot be inserted.\n";
			return i + 1;
		}
	}

}

int TwoDimHash::search(int val) {
	int index = hash(val);

	for (int i = 0; i < COL; i++) {
		if (this->arr[index][i] == val) {
			std::cout << "2D_NOTE: The value " << val << " can be found.\n";
			return i + 1;
		}
		if (i == COL - 1 || !this->arr[index][i]) {
			std::cout << "2D_NOTE: The value " << val << " cannot be found.\n";
			return i + 1;
		}
	}

}

int TwoDimHash::remove(int val) {

	int index = hash(val);

	for (int i = 0; i < COL; i++) {
		if (this->arr[index][i] == val) {
			this->arr[index][i] = 0;
			std::cout << "2D_NOTE: The value " << val << " was removed.\n";
			shiftUp(arr[index], i + 1);
			return i + 1;
		}
		else if (!this->arr[index][i]) {
			return i + 1;
		}
		if (i == COL - 1) {
			std::cout << "2D_NOTE: The value " << val << " cannot be removed.\n";
			return i + 1;
		}
	}

}

void TwoDimHash::print() {
	std::cout << "2D Hash Table [100][5]\n";
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//if (this->arr[i][j] == 0) break;
			std::cout << this->arr[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

int TwoDimHash::hash(int val) {
	return val % 100;
}

void TwoDimHash::shiftUp(int arr[], int i) {

	if (!(i < COL)) {
		return;
	}
	
	if (!arr[i]) {
		return;
	}

	arr[i - 1] = arr[i];
	arr[i] = 0;
	i++;

	shiftUp(arr, i);
}