/* init
 * Get the information of fields from stdin.
 * It uses new statement for the dynamic variables.
 * These are freed in `int main()` in main.cpp.
 */
#include <iostream>
#include <string>
#include <vector>
#include "h/init"
#include "h/extern"

void readHeaderSettings() {
	int contZeroCount = 0;
	std::cin >> N >> repeatNum >> delayTime >> dataSet >> shouldClearScreen >> shouldUseColor;
	while( contZeroCount < 2 ) {	// check whether '0' is set 2 times continuously, i.e. start of the input of field
		std::string streamLine;
		streamLine.reserve(100);
		std::cin >> streamLine;
		if( streamLine[0] == '0' ) contZeroCount++;
		else	contZeroCount = 0;
	}
}

void allocateArrays() {
	field.resize(N);
	for(int i=0; i<N; i++) {
		field.at(i).resize(N);
	}
}

void readFieldInfo() {
	for(int i=0; i<dataSet; i++) {
		int x_setTrue, y_setTrue;
		std::cin >> x_setTrue >> y_setTrue;
		field.at(x_setTrue).at(y_setTrue).setStatus(true);
	}
}
