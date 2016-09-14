#include <iostream>
void signalHandler(int param) {
	std::cerr << std::endl << "Program terminated by Ctrl-C." << std::endl;
	std::cout << "\033[49m";
	exit(1);
}

