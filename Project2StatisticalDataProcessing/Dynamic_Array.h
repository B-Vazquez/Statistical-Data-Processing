#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

class Dynamic_Array {
public:
	// Constructors
	Dynamic_Array(); // Default constructor
	Dynamic_Array(const Dynamic_Array&); // Copy constructor

	// Destructor
	~Dynamic_Array();

	// Operators
	const Dynamic_Array& operator = (const Dynamic_Array&); // Assignment operator
	double& operator [] (size_t); // Subscript operator (lvalue)
	const double& operator [] (size_t) const; // Subscript operator (rvalue)

	// Class-member functions
	size_t size() const; // Returns the size of the array
	bool empty() const; // Checks if the array is empty
	void push_back(double); // Inserts an element at the end of the array
	
private:
	// Data Fields
	static const size_t DEFAULT_CAPACITY; // Default capacity when an empty array is created
	size_t capacity; // Stores the maximum capacity of the array
	size_t num_of_items; // Stores the number of elements currently in the array
	double* data; // Stores the elements in the array

	//Class-member functions
	void resize(); // Doubles the capacity of the array
};

#endif 