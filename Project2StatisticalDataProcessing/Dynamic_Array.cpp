#include "Dynamic_Array.h"

// Default capacity
const size_t Dynamic_Array::DEFAULT_CAPACITY = 10;

// Default constructor
Dynamic_Array::Dynamic_Array() : capacity(DEFAULT_CAPACITY), num_of_items(0) {
	data = new double[capacity];
}

// Copy constructor
Dynamic_Array::Dynamic_Array(const Dynamic_Array& other) {
	data = NULL;
	*this = other;
}

// Destructor
Dynamic_Array::~Dynamic_Array() {
	if (data) { delete[] data; }
}

// Operators

// Deep-copy assignment operator. This ensures a new array is allocated
// and every stored element is copied into the destination object.
const Dynamic_Array& Dynamic_Array::operator = (const Dynamic_Array& rhs) {
	// Step 1: Avoid self-assignment
	if (this != &rhs) {
		// Step 2: Release dynamic memory before reusing the object.
		if (data) {
			delete[] data;
			data = NULL;
		}
		// Step 3: Copy size-related state.
		capacity = rhs.capacity;
		num_of_items = rhs.num_of_items;
		// Step 4: Allocate a new storage block and copy the stored values.
		if (num_of_items <= capacity) {
			data = new double[capacity];
			for (size_t i = 0; i < num_of_items; i++) {
				data[i] = rhs.data[i];
			}
		}
	}
	// Step 5: Return the assigned object.
	return *this;
}

// Subscript value (lvalue)
double& Dynamic_Array::operator [] (size_t index) {
	return data[index];
}

// Subscript value (rvalue)
const double& Dynamic_Array::operator [] (size_t index) const {
	return data[index];
}

// Class-member functions

/*	Returns the number of elements currently stored.
	@return: the current size of the array
*/
size_t Dynamic_Array::size() const {
	return num_of_items;
}

/*	Checks whether the array currently contains any elements.
	@return: true if the array is empty, false otherwise
*/
bool Dynamic_Array::empty() const {
	return !size();
}

/*	Inserts an element at the end of the array.
	@param element: Value to append to the array
*/
void Dynamic_Array::push_back(double element) {
	if (num_of_items == capacity) {
		resize();
	}
	data[num_of_items++] = element;
}

// Doubles the underlying storage capacity when the current buffer is full.
void Dynamic_Array::resize() {
	capacity *= 2;
	double* new_data = new double[capacity];
	for (size_t i = 0; i < num_of_items; i++) {
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
}