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
const int NOT_FOUND = -1;
const std::string TO_BACKWARD_ONE_LINE = "\033[A";

void LifeSearch();
inline void LifeChange();
void LifePrint(bool isSq);

int main(int argc, char **argv) {
	std::vector<std::string> v(argv, argv + argc);
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
	LifePrint(false);
	sleep(1);

	for(int i=1; i<=kaisuu; i++) {
		if( argc == 1 )		usleep(delayTime * 1000);
		else if( v[1].find("man") != NOT_FOUND )	getchar();
		if( shouldClearScreen ) {
			for(int j=0; j<=N; j++) {
				std::cout << TO_BACKWARD_ONE_LINE;
			}
		}
		std::cout << i << "     " << std::endl;
		LifeSearch();
		LifeChange();
		LifePrint(false);
	}

	delete[](field);
}

// The core part of this program.
void LifeSearch() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			int countAlive = 0;
			countAlive	= cellRead(i-1, j-1) + cellRead(i, j-1) + cellRead(i+1, j-1)
						+ cellRead(i-1, j) + cellRead(i+1, j)
						+ cellRead(i-1, j+1) + cellRead(i, j+1) + cellRead(i+1, j+1);
			if( field[i][j].getStatus() == true ) {
				if( countAlive == 2 || countAlive == 3 )
					field[i][j].setNextStatus(true);
			}else if( field[i][j].getStatus() == false ) {
				if( countAlive == 3 )
					field[i][j].setNextStatus(true);
			}
		}
	}
}

inline void LifeChange() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			field[i][j].goToNextStep();
		}
	}
}

void LifePrint(bool isSq) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if( isSq == false ) {
				std::cout << (int)(field[i][j].getStatus()) << " ";
			}else{
				if( field[i][j].getStatus() == 0 )	printf("□");
				else	printf("■");
			}
		}
		std::cout << std::endl;
	}
}
