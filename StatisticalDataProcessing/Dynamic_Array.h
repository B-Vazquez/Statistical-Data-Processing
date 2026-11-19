#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>

class Dynamic_Array {
public:
	// Constructors
	Dynamic_Array(); // Creates an array with the default starting capacity.
	Dynamic_Array(const Dynamic_Array&); // Copy constructor.

	// Destructor
	~Dynamic_Array();

	// Operators
	const Dynamic_Array& operator = (const Dynamic_Array&); // Deep-copy assignment operator.
	double& operator [] (size_t); // Returns a writable element reference.
	const double& operator [] (size_t) const; // Returns a read-only element reference.
	double& at(size_t); // Returns a writable element reference; throws std::out_of_range if index is invalid.
	const double& at(size_t) const; // Returns a read-only element reference; throws std::out_of_range if index is invalid.

	// Class-member functions
	size_t size() const; // Returns the number of stored elements.
	bool empty() const; // Reports whether the array is empty.
	void push_back(double); // Appends an element to the end of the array.
	
private:
	// Data Fields
	static const size_t DEFAULT_CAPACITY; // Default capacity when an empty array is created
	size_t capacity; // Stores the maximum capacity of the array
	size_t num_of_items; // Stores the number of elements currently in the array
	double* data; // Stores the elements in the array

	//Class-member functions
	void resize(); // Doubles the capacity of the array
	void swap(Dynamic_Array&) noexcept; // Exchanges the storage and size state with another array.
};

#endif 