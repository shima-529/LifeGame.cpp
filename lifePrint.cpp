#include <iostream>
#include <string>
#include <vector>
#include "h/extern"

enum class ANSI_Color {
	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
};

std::string convertToPrintText(Cell target, bool isColor) {
	if( isColor == false )
		return std::to_string(target.getStatus());

	if( target.getStatus() == true )
		return "\033[4" + std::to_string(static_cast<int>(ANSI_Color::BLACK)) + "m" +  " ";
	else
		return "\033[4" + std::to_string(static_cast<int>(ANSI_Color::WHITE)) + "m" + " ";
}

void LifePrint(std::string str, bool isColor, bool isCurBack) {
	const static std::string TO_BACKWARD_ONE_LINE = "\033[A";
	if( isCurBack )
		for(int i=0; i<N+1; i++) {
			std::cout << TO_BACKWARD_ONE_LINE;
		}

	std::cout << str << ":     " << std::endl;

	for(auto &iterX: field) {
		for(auto &iterY: iterX) {
			std::cout << convertToPrintText(iterY, isColor) << " ";
		}
		std::cout << "\033[49m" << std::endl;
	}
}
