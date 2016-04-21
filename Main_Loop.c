#include <stdio.h>

#include <time.h>

#include <stdlib.h>

#include "PCB_Queue.h"

#include "PCB.h"


#include "schedule.h"

unsigned long int SYS_STACK = 0;



void main(void) {

	srand(time(NULL));

	PCB_Queue_p List_PCB = PCB_Queue_construct();
 
	PCB_p tpcb;
	int randNumPCB = 0;

	int i =0;

	unsigned long int cpu_pc = 0;

	//very first running proceess
	
PCB_p temp = PCB_construct();
	PCB_init(temp);

	while(1){
	
	randNumPCB = rand() % 6;


	for(i =0; i < randNumPCB && List_PCB->size < 31; i++){

		printf("\nthe random Number is %d \n" , randNumPCB);

		tpcb = PCB_construct();
		PCB_init(tpcb);

		PCB_Queue_enqueue(List_PCB,tpcb);

	}

	
	
	//running
	cpu_pc = PCB_get_pc(temp);
	cpu_pc += rand() % 1001 + 3000; 
	
	//push onto sys stack
	SYS_STACK = cpu_pc;	
	
	pseudo_ISR(List_PCB, &temp, cpu_pc);
		
	}//ends while
}