#pragma once
#include <iostream>
class TwoDimHash
{
	static const int ROW = 100, COL = 5;
private:
	int arr[ROW][COL] = {};

	/**
	 Hashes given integer

	 Parameters: val: int
	 Return value: int
	 */
	int hash(int);

	//handeling removing 
	void shiftUp(int arr[], int i);

public:
	TwoDimHash();
	~TwoDimHash();


	/**
	 Inserts given value into hash table. Returns number of spots checked before insertion.
	
	 Parameters: val: int
	 Return value: int
	 */
	int insert(int);

	/**
	 Searches for given value, prints if integer is found, return total number of spots searched.

	 Parameters: val: int
	 Return value: int
	*/
	int search(int);

	/**
	 Removes given value. Returns total number of spots searched.

	 Parameters: val: int
	 Return value: int
	*/
	int remove(int);

	/**
	 prints formatted hash table

	 Parameters: val: int
	 Return value: None
	*/
	void print();
};