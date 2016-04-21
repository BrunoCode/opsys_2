#pragma once
#include "PCB.h"

typedef struct PCB_Queue * PCB_Queue_p; // queue pointer for malloc

//
struct node {
	PCB_p value; //pcb
	struct node * next_node;
};

struct PCB_Queue {
	struct node * first_node_ptr;
	struct node * last_node_ptr;
	int size;
};
PCB_Queue_p PCB_Queue_construct(void);
void PCB_Queue_destruct(PCB_Queue_p p);
int PCB_Queue_is_empty(PCB_Queue_p p); // 0 = isEmpty 1 = notEmpty
void PCB_Queue_enqueue(PCB_Queue_p p, PCB_p value); //not sure void or int (for error)
PCB_p PCB_Queue_dequeue(PCB_Queue_p p);
void PCB_Queue_toString(PCB_Queue_p p);
void PCB_Queue_toString2(PCB_Queue_p p); //enqueued



