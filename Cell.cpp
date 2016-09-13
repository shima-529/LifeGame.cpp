/* Cell
 * defines mathods of Cell class.
 * This includes get/set mathods and neighbor information.
 * 
 */
#include "h/Cell"
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
/* Cell *getNeighbor(int idx) { */
/* 	return neighbor[idx]; */
/* } */
void Cell::setStatus(bool param) {
	status = param;
}
void Cell::setNextStatus(bool p) {
	nextStatus = p;
}
/* void Cell::setNeighbor(int idx, Cell *dest) { */
/* 	neighbor[idx] = dest; */
/* } */

void Cell::goToNextStep() {
	status = nextStatus;
	nextStatus = false;
}

bool Cell::compareOwnStatus() {
	return !(status ^ nextStatus);
}
