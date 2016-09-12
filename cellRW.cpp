/* cellRW
 * By using these funcs, values can be set/read.
 * This includes R/W and the discriminant func(is_outOfRange).
 * 
 */
#include "h/Cell"
#include "h/extern"

template<typename T>
inline bool is_outOfRange(T param) {
	return (param < 0 || param >= N) ? true : false;
}

template<typename T>
inline bool is_outOfRange(T p1, T p2) {
	return is_outOfRange(p1) | is_outOfRange(p2);
}

bool cellRead(const int x, const int y) {
	// This return value is added to the total neighbor-alive number.
	// Therefore, returning (-1) occurs bugs. Boolean value is the most suitable.
	if( is_outOfRange(x, y) )	return false;
	return field[x][y].getStatus();
}

void cellWrite(const int x, const int y, bool nextStatus) {
	if( is_outOfRange(x, y) )	return;
	field[x][y].setStatus(nextStatus);
}
