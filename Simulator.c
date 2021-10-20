#include "simulator.h"

int pinEvent;

void generateEvent(int sim) {
	pinEvent = (sim != 0) ? 1<<sim : 0; 
}
