/* init
 * Get the information of fields from stdin.
 * It uses new statement for the dynamic variables.
 * These are freed in `int main()` in main.cpp.
 */
#include <iostream>
#include <string>
#include "h/init"
#include "h/extern"
#include "h/Cell"

void readHeaderSettings() {
	int contZeroCount = 0;
	std::cin >> N >> kaisuu >> delayTime >> dataSet >> shouldClearScreen;
	while( contZeroCount < 2 ) {	// check whether '0' is set 2 times continuously, i.e. start of the input of field
		std::string streamLine;
		streamLine.reserve(100);
		std::cin >> streamLine;
		if( streamLine[0] == '0' ) contZeroCount++;
		else	contZeroCount = 0;
	}
}

void allocateArrays() {
	field = new Cell *[N];
	for(int i=0; i<N; i++) {
		field[i] = new Cell[N];
	}
}

void readField() {
	for(int i=0; i<dataSet; i++) {
		int x_setTrue, y_setTrue;
		std::cin >> x_setTrue >> y_setTrue;
		// TODO: エラー処理を書く(outOfRange)
		field[x_setTrue][y_setTrue].setStatus(true);
	}
}
