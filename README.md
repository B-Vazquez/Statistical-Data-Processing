# Statistical Data Processing

This project reads a text file containing x-y pairs and computes basic statistical information for the two columns of data. The program writes its results to `results.txt`.

## What it does

- Reads numeric x-y pairs from `data.txt`
- Computes the number of pairs read
- Calculates the arithmetic mean for both columns
- Computes standard deviation for both columns
- Calculates the correlation coefficient
- Produces a simple linear-fitting summary using the slope and intercept

## Implementation note

The hand-rolled `Dynamic_Array` is deliberate for this project to demonstrate dynamic storage and memory management. Its `at()` accessor checks bounds; `operator[]` remains unchecked.

## Build and run

From the workspace root, compile the project with:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic StatisticalDataProcessing/VazquezStatisticalDataProcessing.cpp StatisticalDataProcessing/Dynamic_Array.cpp -o statistical-data-processing
```

Run it from the workspace root so `data.txt` is found:

```sh
./statistical-data-processing
```

The `.sln` file is for Visual Studio. In Visual Studio Code, install the Microsoft C/C++ extension and use **Run and Debug** with the **Debug Statistical Data Processing** configuration. Its pre-launch task builds the program with `/usr/bin/g++`; the debugger uses `/usr/bin/gdb`. Both must be installed. The VS Code debugger runs it with `StatisticalDataProcessing/` as its working directory so it can find that directory's `data.txt`.

## Input and output assumptions

- The input file must be named `data.txt`
- The input file should contain one numeric x value and one numeric y value per line, separated by whitespace
- The program expects the file to be well-formed; malformed input will currently produce an error message and terminate early
- The output is written to `results.txt` in the current working directory

## Notable file roles

- `VazquezStatisticalDataProcessing.cpp`: main program logic and statistical calculations
- `Dynamic_Array.h`: declaration of the custom dynamic array class
- `Dynamic_Array.cpp`: dynamic array implementation
- `data.txt`: sample input data
- `results.txt`: generated output from a successful run

## Known limitations / requirements

- The program assumes the current working directory contains `data.txt`
- Input is parsed as plain numeric values; non-numeric or incomplete data will trigger a runtime error