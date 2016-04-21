#include "PCB_Queue.h"


void pseudo_ISR(PCB_Queue_p theList, PCB_p * thePcb, unsigned long int thePC);

void scheduler(PCB_Queue_p theList, PCB_p * thePcb, unsigned long int thePC);
		
void dispatcher(PCB_Queue_p theList, PCB_p * thePcb, unsigned long int thePC);
