/* init
 * Get the information of fields from stdin.
 * It uses new statement for the dynamic variables.
 * These are freed in `int main()` in main.cpp.
 */
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "h/extern"

void readHeaderSettings() {
	int contZeroCount = 0;
	std::cin >> N >> repeatNum >> delayTime >> dataSet >> shouldClearScreen >> shouldUseColor;
	while( contZeroCount != 2 ) {	// check whether '0' is set 2 times continuously, i.e. start of the input of field
		std::string streamLine;
		std::cin >> streamLine;
		if( streamLine[0] == '0' ) contZeroCount++;
		else	contZeroCount = 0;
	}
}

void allocateArrays() {
	field.resize(N);
	for(int i=0; i<N; i++)
		field.at(i).resize(N);
}

void readFieldInfo() {
	for(int i=1; i<=dataSet; i++) {
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
