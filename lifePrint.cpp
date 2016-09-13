#include <iostream>
#include <string>
#include <vector>
#include "h/Cell"
#include "h/extern"
// #include "h/globalVal"

using std::string;
using std::to_string;

enum class ANSI_Color {
	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
};

string convertToPrintText(Cell target, bool isColor) {
	if( isColor == false )
		return to_string(target.getStatus());

	if( target.getStatus() == true )
		return "\033[4" + to_string(static_cast<int>(ANSI_Color::BLACK)) + "m" +  " ";
	else
		return "\033[4" + to_string(static_cast<int>(ANSI_Color::WHITE)) + "m" + " ";
}

void LifePrint(bool isColor) {
	for(auto &iterX: field) {
		for(auto &iterY: iterX) {
			std::cout << convertToPrintText(iterY, isColor) << " ";
		}
		std::cout << "\033[49m" << std::endl;
	}
}

void CursorBack() {
	const static string TO_BACKWARD_ONE_LINE = "\033[A";
	for(int i=0; i<N+1; i++) {
			std::cout << TO_BACKWARD_ONE_LINE;
		}
}
