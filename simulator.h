#include "trainCommandsIO.h"

typedef struct {
	int event;
	int IDTask;
	int delayTime;
} Simulator;

void generateEvent(int sim);
