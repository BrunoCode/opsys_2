#include <stdio.h>
#include "schedule.h"


void pseudo_ISR(PCB_Queue_p theList, PCB_p * thePcb, unsigned long int  thePC) {

	PCB_set_state(*thePcb ,PCB_STATE_INTERRUPTED); // not sure which one
	
	scheduler(theList, thePcb, thePC); 
}


void scheduler(PCB_Queue_p theList, PCB_p * thePcb, unsigned long int thePC){		

		PCB_set_state(* thePcb , PCB_STATE_READY);
		dispatcher(theList, thePcb, thePC);
}

void dispatcher(PCB_Queue_p theList, PCB_p * thePcb, unsigned long int thePC){
	PCB_set_pc(*thePcb, thePC);
	PCB_Queue_enqueue(theList ,*thePcb);
	printf("\n pc : %u \n", thePC);
	//getchar();
	*thePcb = PCB_Queue_dequeue(theList);
}
