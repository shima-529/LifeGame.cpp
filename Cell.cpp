/* Cell
 * defines mathods of Cell class.
 * This includes get/set mathods and neighbor information.
 * 
 */
#include "h/Cell"
CELL::CELL() {
	status = false;
	nextStatus = false;
}
bool CELL::getStatus() {
	return status;
}
bool CELL::getNextStatus() {
	return nextStatus;
}
/* CELL *getNeighbor(int idx) { */
/* 	return neighbor[idx]; */
/* } */
void CELL::setStatus(bool param) {
	status = param;
}
void CELL::setNextStatus(bool p) {
	nextStatus = p;
}
/* void CELL::setNeighbor(int idx, CELL *dest) { */
/* 	neighbor[idx] = dest; */
/* } */

void CELL::goToNextStep() {
	status = nextStatus;
	nextStatus = false;
}
