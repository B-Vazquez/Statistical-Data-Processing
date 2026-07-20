#include "Dynamic_Array.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// Functions used in the main() function
double avg(const Dynamic_Array&); // Calculates the average of all values stored in a given dynamic array
double stdDev(const Dynamic_Array&); // Calculates the standard deviation of all values stored in a given dynamic array
double corrCoef(const Dynamic_Array&, const Dynamic_Array&); // Calculates the correlation coefficient of all values stored in the given dynamic arrays
double slope(const Dynamic_Array&, const Dynamic_Array&); // Calculates the slope of all values stored in the given dynamic arrays
double intercept(const Dynamic_Array&, const Dynamic_Array&); // Calculates the intercept of all values stored in the given dynamic arrays

int main(int argc, char * argv[]) {
	// Opens the input file.
	ifstream inputFile("data.txt");

	// Checks if input file was opened successfully.
	if (!inputFile) {
		cout << argv[0] << endl;
		cout << "Error: input file does not exist. Please encure the input file is stored in the above directory." << endl;
		system("pause");
		return -1;
	}

	// Opens/creates the output file.
	ofstream outputFile("results.txt");

	Dynamic_Array xArray; // Dynamic array to store the values of the given X's
	Dynamic_Array yArray; // Dynamic array to store the values of the given Y's
	double xToPass; // Temporarily stores the current x to pass into xArray
	double yToPass; // Temporarily stores the current y to pass into yArray

	// Loop to pass all x and y values to their given array
	while (inputFile >> xToPass >> yToPass) {
		xArray.push_back(xToPass);
		yArray.push_back(yToPass);
	}

	// Writes num the number of x-y pairs to the output file
	outputFile << "Number of x-y pairs read: " << xArray.size() << endl << endl;
	
	/*	Writes the average of all the stored X's to the output file
		and sets all future double's to be set to 4 digits after the decimal*/
	outputFile << fixed << setprecision(4) << "Algebraic average of x: " << avg(xArray) << endl;

	// Writes the average of all stored Y's to the output file
	outputFile << "Algebraic average of y: " << avg(yArray) << endl;

	// Writes the standard deviation of the x values to the output file
	outputFile << "Standard deviation of x: " << stdDev(xArray) << endl;

	// Writes the standard deviation of the y values to the output file
	outputFile << "Standard deviation of y: " << stdDev(yArray) << endl << endl;

	// Writes the correlation coefficient of the x and y values to the output file
	outputFile << "Correlation coefficient: " << corrCoef(xArray, yArray) << endl << endl;

	// Writes the linear fitting function of the x and y values to output file
	outputFile << "Linear fitting function:" << endl << endl;
	outputFile << "y = " << slope(xArray, yArray) << " + " << intercept(xArray, yArray) << endl << endl;

	// Writes the slope of the x and y values to the output file
	outputFile << "Slope: " << slope(xArray, yArray) << endl;

	// Writes the intercept of the x and y values to the output file
	outputFile << "Intercept: " << intercept(xArray, yArray) << endl;
	

	// Closes input and output file
	inputFile.close();
	outputFile.close();

	return 0;
}


/*	Calculates the average of all values stored in a given dynamic array
	@param array: Given dynamic array
	@return: The average of all values stored in the given dynamic array
*/
double avg(const Dynamic_Array& array) {
	double sumOfValues = 0;
	for (size_t i = 0; i < array.size(); i++) {
		sumOfValues += array[i];
	}
	return sumOfValues / array.size();
}

/*	Calculates the standard deviation of all values stored in a given dynamic array
	@param array: Given dynamic array
	@return: The standard deviation of the given array
*/
double stdDev(const Dynamic_Array& array) {
	double sumOfValues = 0; 
	double avgOfValues = avg(array); 
	for (size_t i = 0; i < array.size(); i++) {
		sumOfValues += pow(array[i] - avgOfValues, 2);
	}
	return sqrt(sumOfValues / array.size());
}

/*	Calculates the correlation coefficient of all values stored in the given dynamic arrays
	@param xArray: Given dynamic array of all X values
	@param yArray: Given dynamic array of all Y values
	@return: The correlation coefficient of all values stored in the given dynamic arrays
*/
double corrCoef(const Dynamic_Array& xArray, const Dynamic_Array& yArray) {
	double sumOfX = 0, sumOfY = 0, sumOfXandY = 0;
	double avgOfX = avg(xArray), avgOfY = avg(yArray);
	for (size_t i = 0; i < xArray.size(); i++) {
		sumOfXandY += (xArray[i] - avgOfX) * (yArray[i] - avgOfY);
		sumOfX += pow(xArray[i] - avgOfX, 2);
		sumOfY += pow(yArray[i] - avgOfY, 2);
	}
	return sumOfXandY / (sqrt(sumOfX) * sqrt(sumOfY));
}

/*	Calculates the slope of all values stored in a given dynamic array
	@param xArray: Given dynamic array of all X values
	@param yArray: Given dynamic array of all Y values
	@return: The slope of all values stored in the given dynamic arrays
*/
double slope(const Dynamic_Array& xArray, const Dynamic_Array& yArray) {
	double sumOfX = 0, sumOfY = 0;
	double sumOfXtimesY = 0, sumOfXSquared = 0;
	for (size_t i = 0; i < xArray.size(); i++) {
		sumOfXtimesY += xArray[i] * yArray[i];
		sumOfX += xArray[i];
		sumOfY += yArray[i];
		sumOfXSquared += pow(xArray[i], 2);
	}
	return (xArray.size() * sumOfXtimesY - (sumOfX * sumOfY)) / (xArray.size() * sumOfXSquared - pow(sumOfX, 2));
}

/*	Calculates the intercept of all values stored in a given dynamic array
	@param xArray: Given dynamic array of all X values
	@param yArray: Given dynamic array of all Y values
	@return: The intercept of all values stored in the given dynamic arrays
*/
double intercept(const Dynamic_Array& xArray, const Dynamic_Array& yArray) {
	double sumOfX = 0, sumOfY = 0;
	for (size_t i = 0; i < xArray.size(); i++) {
		sumOfX += xArray[i];
		sumOfY += yArray[i];
	}
	return (sumOfY - slope(xArray, yArray) * sumOfX) / xArray.size();
}