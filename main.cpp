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
#include "h/lifePrint"

using std::string;
using std::to_string;

void LifeSearch();
int CountNeighbor(int x, int y);
inline void LifeChange();

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
	// Main Loop
	for(int i=1; i<=kaisuu; i++) {
		usleep(delayTime * 1000);
		if( shouldClearScreen )	CursorBack();
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
			int countAlive = CountNeighbor(i, j);
			if( field.at(i).at(j).getStatus() == true && (countAlive == 2 || countAlive == 3) )
				field.at(i).at(j).setNextStatus(true);
			else if( field.at(i).at(j).getStatus() == false && countAlive == 3) 
				field.at(i).at(j).setNextStatus(true);
		}
	}
}

int CountNeighbor(int x, int y) {
	const static int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
	const static int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
	int ret = 0;
	for(int index=0; index<8; index++) {
		ret += cellRead(x + dx[index], y + dy[index]);
	}
	return ret;
}

inline void LifeChange() {
	for(auto &iterX: field)
		for(auto &iterY: iterX)
			iterY.goToNextStep();
}

