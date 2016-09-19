/* Cell
 * defines mathods of Cell class.
 * This includes get/set mathods.
 * 
 */
#include "h/Cell"

int Cell::N;
int Cell::repeatNum;
int Cell::delayTime;
int Cell::dataSet;
bool Cell::shouldClearScreen;
bool Cell::shouldUseColor;

Cell::Cell() {
	status = false;
	nextStatus = false;
}
bool Cell::getStatus() {
	return status;
}
bool Cell::getNextStatus() {
	return nextStatus;
}
void Cell::setStatus(bool param) {
	status = param;
}
void Cell::setNextStatus(bool p) {
	nextStatus = p;
}

void Cell::goToNextStep() {
	status = nextStatus;
	nextStatus = false;
}

bool Cell::compareOwnStatus() {
	return !(status ^ nextStatus);
}
