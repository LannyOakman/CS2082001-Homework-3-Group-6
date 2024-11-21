#pragma once
class TwoDimHash
{
private:
	int* arr[100][5] = {0};

public:
	TwoDimHash();
	~TwoDimHash();


	/**
	 Inserts given value into hash table. Returns number of spots checked before insertion.
	
	 Parameters: val: int
	 Return value: int
	 */
	int Insert(int);

	/**
	 Searches for given value, prints if integer is found, return total number of spots searched.

	 Parameters: val: int
	 Return value: int
	*/
	int Search(int);

	/**
	 Removes given value. Returns total number of spots searched.

	 Parameters: val: int
	 Return value: int
	*/
	int Remove(int);

	/**
	 prints formatted hash table

	 Parameters: val: int
	 Return value: None
	*/
	void Print();

};