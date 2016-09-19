/* init
 * Get the information of fields from stdin.
 * It uses new statement for the dynamic variables.
 * These are freed in `int main()` in main.cpp.
 */
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "h/Cell"
#include "h/global"

void readHeaderSettings() {
	int contZeroCount = 0;
	std::cin >> Cell::N >> Cell::repeatNum >> Cell::delayTime >> Cell::dataSet >> Cell::shouldClearScreen >> Cell::shouldUseColor;
	while( contZeroCount != 2 ) {	// check whether '0' is set 2 times continuously, i.e. start of the input of field
		std::string streamLine;
		std::cin >> streamLine;
		if( streamLine[0] == '0' ) contZeroCount++;
		else	contZeroCount = 0;
	}
}

void allocateArrays() {
	field.resize(Cell::N);
	for(int i=0; i<Cell::N; i++)
		field.at(i).resize(Cell::N);
}

void readFieldInfo() {
	for(int i=1; i<=Cell::dataSet; i++) {
		int x_setTrue, y_setTrue;
		std::cin >> x_setTrue >> y_setTrue;
		try {
			field.at(x_setTrue).at(y_setTrue).setStatus(true);
		} catch(std::out_of_range &ex) {
			std::cout << "Wrong designation found on input " << i << "." << std::endl;
			std::cout << "Program terminated." << std::endl;
			exit(1);
		}
	}
}
