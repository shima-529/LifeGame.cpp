/* main
 * contains funcs which constitutes the main part.
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include "h/init"
#include "h/globalVal"
#include "h/system"
#include "h/cellRW"

using std::string;
using std::to_string;

const int NOT_FOUND = -1;
const string TO_BACKWARD_ONE_LINE = "\033[A";

enum ANSI_Color {
	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
};

void LifeSearch();
inline void LifeChange();
void LifePrint(bool isColor);
string convertToPrintText(Cell& target, bool isColor);
void CursorBack();

int main(int argc, char **argv) {
	std::vector<string> v(argv, argv + argc);
	std::cout << "==========================================" << std::endl; //{{{
	std::cout << "             L I F E  G A M E             " << std::endl;
	std::cout << " Please input field length and loop times." << std::endl;
	std::cout << " Redirection from txt file is recommended." << std::endl;
	std::cout << "==========================================" << std::endl;
	if( argc > 1 && v[1].find("h") != NOT_FOUND ){
		std::cout << "with 'manual' option, steps will not proceed until RETURN key is pressed.\n";
		return 0;
	} //}}}
	readHeaderSettings();
	allocateArrays();

	readField();
	std::cout << "Start:" << std::endl;
	LifePrint(shouldUseColor);
	sleep(1);

	for(int i=1; i<=kaisuu; i++) {
		usleep(delayTime * 1000);
		if( shouldClearScreen )
			CursorBack();
		std::cout << i << "     " << std::endl;
		LifeSearch();
		LifeChange();
		LifePrint(shouldUseColor);
	}

	return 0;
}

// The core part of this program.
void LifeSearch() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			int countAlive = 0;
			countAlive	= cellRead(i-1, j-1) + cellRead(i  , j-1) + cellRead(i+1, j-1)
						+ cellRead(i-1, j  ) + cellRead(i+1, j  )
						+ cellRead(i-1, j+1) + cellRead(i  , j+1) + cellRead(i+1, j+1);
			if( field.at(i).at(j).getStatus() == true && (countAlive == 2 || countAlive == 3) )
				field.at(i).at(j).setNextStatus(true);
			else if( field[i][j].getStatus() == false && countAlive == 3) 
				field.at(i).at(j).setNextStatus(true);
		}
	}
}

inline void LifeChange() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			field.at(i).at(j).goToNextStep();
		}
	}
}

void LifePrint(bool isColor) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			std::cout << convertToPrintText(field.at(i).at(j), isColor) << " ";
		}
		std::cout << "\033[49m" << std::endl;
	}
}

string convertToPrintText(Cell& target, bool isColor) {
	if( !isColor ) return to_string(target.getStatus());

	if( target.getStatus() )	return "\033[4" + to_string(BLACK) + "m" +  " ";
	else	return "\033[4" + to_string(WHITE) + "m" + " ";
}

void CursorBack() {
	for(int j=0; j<=N; j++) {
			std::cout << TO_BACKWARD_ONE_LINE;
		}
}
