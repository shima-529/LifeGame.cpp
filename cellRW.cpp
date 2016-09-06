/* cellRW
 * By using these funcs, values can be set/read.
 * This includes R/W and the discriminant func(is_outOfRange).
 * 
 */
#include "h/init"
#include "h/extern"
const int NOT_FOUND = -1;

inline bool is_outOfRange(int param) {
	return (param < 0 || param >= N) ? true : false;
}

int cellRead(int x, int y) {
	if( is_outOfRange(x) )	return NOT_FOUND;
	if( is_outOfRange(y) )	return NOT_FOUND;
	return field[x][y].getStatus();
}

void cellWrite(int x, int y, int content) {
	if( is_outOfRange(x) )	return;
	if( is_outOfRange(y) )	return;
	field[x][y].setStatus(content);
}
