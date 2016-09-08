/* cellRW
 * By using these funcs, values can be set/read.
 * This includes R/W and the discriminant func(is_outOfRange).
 * 
 */
#include "h/init"
#include "h/extern"
const int NOT_FOUND = -1;

template<typename T>
inline bool is_outOfRange(T param) {
	return (param < 0 || param >= N) ? true : false;
}

template<typename T>
inline bool is_outOfRange(T p1, T p2) {
	return is_outOfRange(p1) | is_outOfRange(p2);
}

bool cellRead(int x, int y) {
	// This return value is added to the total neighbor-alive number.
	// Therefore, returning (-1) occurs bugs. Boolean value is the most suitable.
	if( is_outOfRange(x, y) )	return false;
	// if( is_outOfRange(x, y) )	return NOT_FOUND;
	// if( is_outOfRange(y) )	return NOT_FOUND;
	return field[x][y].getStatus();
}

void cellWrite(int x, int y, bool nextStatus) {
	if( is_outOfRange(x, y) )	return;
	field[x][y].setStatus(nextStatus);
}
