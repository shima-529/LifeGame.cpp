/* cellRW
 * By using these funcs, values can be set/read.
 * This includes R/W and the discriminant func(is_outOfRange).
 * 
 */
#include <vector>
#include <stdexcept>
#include "h/extern"

bool cellRead(const int x, const int y) {
	try {
		return field.at(x).at(y).getStatus();
	} catch(std::out_of_range &ex) {
		return false;
	}
}

void cellWrite(const int x, const int y, bool nextStatus) {
	try {
		field.at(x).at(y).setStatus(nextStatus);
	} catch(std::out_of_range &ex) {
		return;
	}
}
