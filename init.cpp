/* init
 * Get the information of fields from stdin.
 * It uses new statement for the dynamic variables.
 * These are freed in `int main()` in main.cpp.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ios>
#include "h/Cell"
#include "h/global"

void readHeaderSettings(std::ifstream &ifs) {
	int contZeroCount = 0;
	ifs >> Cell::N >> Cell::repeatNum >> Cell::delayTime >> Cell::dataSet >> Cell::shouldClearScreen >> Cell::shouldUseColor;
	while( contZeroCount != 2 ) {	// check whether '0' is set 2 times continuously, i.e. start of the input of field
		std::string streamLine;
		ifs >> streamLine;
		if( streamLine[0] == '0' ) contZeroCount++;
		else	contZeroCount = 0;
	}
}

void allocateArrays() {
	field.resize(Cell::N);
	for(int i=0; i<Cell::N; i++)
		field.at(i).resize(Cell::N);
}

void readFieldInfo(std::ifstream &ifs) {
	for(int i=1; i<=Cell::dataSet; i++) {
		int x_setTrue, y_setTrue;
		try {
			ifs >> x_setTrue >> y_setTrue;
			field.at(x_setTrue).at(y_setTrue).setStatus(true);
		} catch(std::out_of_range &ex) {
			std::cout << "Wrong designation found on input " << i << "." << std::endl;
			std::cout << "Program terminated." << std::endl;
			exit(1);
		// FIXME
		// } catch (std::ios_base::failure &ex) {
		// 	if( ifs.fail() ) {
		// 		std::cout << "Error: bad file structure." << std::endl;
		// 		std::cout << "Error occurred while setting field values." << std::endl;
		// 	}
		// 	exit(1);
		}
	}
}
