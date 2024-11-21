#pragma once
#include <iostream>


class OneDimHash {
	static const int MAX_SIZE = 500;
	int* table[MAX_SIZE];
	int count;

	/**
	 Hashes given integer

	 Parameters: val: int
	 Return value: int
	 */
	int hashFunc(int);


	/**
	 Checks if a value is currently in table
	 based on a starting index

	 Parameters: index: int, val: int
	 Returns: Int: Negative value for if the value is not in table
				Index of item if item is in table
	 */
	int inTable(int, int);



public:
	OneDimHash() : count(0), table{ nullptr } {};

	~OneDimHash();


	/**
	 Search for integer in table returns 

	 Parameters: val: int
	 Return value: Spots_checked Int
	 */
	int search(int);

	/**
	 Inserts int ptr into table using linear probbing (does not resize)


	 Parameters: val: int
	 Return value: Spots_checked: int
	 */
	int insert(int);

	/*
	 Removes int ptr from table if present 


	 Parameters: val: int
	 Return value: Spots_checked or Replacements made: int
	 */
	int remove(int);

	/*Prints all values in table that aren't nullptr
	* along with their indexes
	* 
	* Parameters: NONE
	* Return: NONE
	*/
	void print();





};
