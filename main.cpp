/* main
 * contains funcs which constitutes the main part.
 * On error, funcs on other files detect it.
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <signal.h>
#include "h/Cell"
#include "h/global"
#include "h/sigInterrupt"
#include "h/init"
#include "h/cellRW"
#include "h/lifePrint"

void iterateChange_storeAsNextStatus();
bool isAllStatusSame();
int countAliveNumAround(int x, int y);
inline void applyChange();

int main(int argc, char **argv) {
	signal(SIGINT, signalHandler);
	if( argc != 2 ) {
		std::cout << "Error: designate a filename to the 1st parameter." << std::endl;
		exit(1);
	}
	std::vector<string> v(argv, argv + argc);
	std::ifstream ifs(argv[1]);
	ifs.exceptions(std::ifstream::eofbit);
	if( ifs.fail() ) {
		std::cout << "Error: failed to read the file." << std::endl;
	}
	std::cout << "==========================================" << std::endl;
	std::cout << "             L I F E  G A M E             " << std::endl;
	// std::cout << " Please input field length and loop times." << std::endl;
	// std::cout << " Redirection from txt file is recommended." << std::endl;
	std::cout << "==========================================" << std::endl;
	readHeaderSettings(ifs);
	allocateArrays();
	readFieldInfo(ifs);

	LifePrint("Start", Cell::shouldUseColor);
	sleep(1);
	// Main Loop
	for(int i=1; i<=Cell::repeatNum; i++) {
		iterateChange_storeAsNextStatus();
		if( isAllStatusSame() ) {
			std::cout << std::endl << "No more changes. Stop." << std::endl;
			break;
		}
		applyChange();
		LifePrint(to_string(i), Cell::shouldUseColor, Cell::shouldClearScreen);
		usleep(Cell::delayTime * 1000);
	}
	return 0;
}

// The core part of this program.
void iterateChange_storeAsNextStatus() {
	for(int i=0; i<Cell::N; i++) {
		for(int j=0; j<Cell::N; j++) {
			int countAlive = countAliveNumAround(i, j);
			if( field.at(i).at(j).getStatus() == true && (countAlive == 2 || countAlive == 3) )
				field.at(i).at(j).setNextStatus(true);
			else if( field.at(i).at(j).getStatus() == false && countAlive == 3)
				field.at(i).at(j).setNextStatus(true);
		}
	}
}

bool isAllStatusSame() {
	for(auto iterX: field)
		for(auto iterY: iterX)
			if( iterY.compareOwnStatus() == false )	return false;
	return true;
}

int countAliveNumAround(int x, int y) {
	const static int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
	const static int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
	int ret = 0;
	for(int index=0; index<8; index++)
		ret += cellRead(x + dx[index], y + dy[index]);
	return ret;
}

inline void applyChange() {
	for(auto &iterX: field)
		for(auto &iterY: iterX)
			iterY.goToNextStep();
}
