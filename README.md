# Statistical Data Processing

This project reads a text file containing x-y pairs and computes basic statistical information for the two columns of data. The program writes its results to `results.txt`.

## What it does

- Reads numeric x-y pairs from `data.txt`
- Computes the number of pairs read
- Calculates the arithmetic mean for both columns
- Computes standard deviation for both columns
- Calculates the correlation coefficient
- Produces a simple linear-fitting summary using the slope and intercept

## Build and run

From the workspace root, compile and run the project with your preferred C++ toolchain. In Visual Studio Code, the provided solution can be used to build and run the project.

## Input and output assumptions

- The input file must be named `data.txt`
- The input file should contain one numeric x value and one numeric y value per line, separated by whitespace
- The program expects the file to be well-formed; malformed input will currently produce an error message and terminate early
- The output is written to `results.txt` in the same directory as the executable

## Notable file roles

- `VazquezProject2.cpp`: main program logic and statistical calculations
- `Dynamic_Array.h`: declaration of the custom dynamic array class
- `Dynamic_Array.cpp`: dynamic array implementation
- `data.txt`: sample input data
- `results.txt`: generated output from a successful run

## Known limitations / requirements

- The program assumes the current working directory contains `data.txt`
- Input is parsed as plain numeric values; non-numeric or incomplete data will trigger a runtime error