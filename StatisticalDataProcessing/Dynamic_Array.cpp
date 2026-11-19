#include "Dynamic_Array.h"

#include <stdexcept>
#include <utility>

// Default capacity
const size_t Dynamic_Array::DEFAULT_CAPACITY = 10;

// Default constructor
Dynamic_Array::Dynamic_Array() : capacity(DEFAULT_CAPACITY), num_of_items(0), data(new double[capacity]) {}

// Copy constructor
Dynamic_Array::Dynamic_Array(const Dynamic_Array& other)
	: capacity(other.capacity), num_of_items(other.num_of_items), data(new double[capacity]) {
	for (size_t i = 0; i < num_of_items; i++) {
		data[i] = other.data[i];
	}
}

// Destructor
Dynamic_Array::~Dynamic_Array() {
	delete[] data;
}

// Operators

// Deep-copy assignment operator. This ensures a new array is allocated
// and every stored element is copied into the destination object.
const Dynamic_Array& Dynamic_Array::operator = (const Dynamic_Array& rhs) {
	if (this != &rhs) {
		Dynamic_Array copy(rhs);
		swap(copy);
	}
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

// Returns a writable element reference or throws if the index is outside the stored elements.
double& Dynamic_Array::at(size_t index) {
	if (index >= num_of_items) {
		throw std::out_of_range("Dynamic_Array index out of range");
	}
	return data[index];
}

// Returns a read-only element reference or throws if the index is outside the stored elements.
const double& Dynamic_Array::at(size_t index) const {
	if (index >= num_of_items) {
		throw std::out_of_range("Dynamic_Array index out of range");
	}
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
	const size_t new_capacity = capacity * 2;
	double* new_data = new double[new_capacity];
	for (size_t i = 0; i < num_of_items; i++) {
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
	capacity = new_capacity;
}

// Exchanges the buffers and their metadata so copy-and-swap can safely transfer ownership.
void Dynamic_Array::swap(Dynamic_Array& other) noexcept {
	using std::swap;
	swap(capacity, other.capacity);
	swap(num_of_items, other.num_of_items);
	swap(data, other.data);
}