#include "PCB_Queue.h"
#include "PCB.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

PCB_Queue_p PCB_Queue_construct(void) {
	PCB_Queue_p list = malloc(sizeof(struct PCB_Queue));
	list->first_node_ptr = NULL;
	list->last_node_ptr = NULL;
	list->size = 0;
	return list;
}
void PCB_Queue_destruct(PCB_Queue_p theList) {
	if (theList->size != 0) {
		struct node* current_ptr = theList->first_node_ptr->next_node;
		struct node* temp_ptr = theList->first_node_ptr;
		int i;
		for (i = 0; i < theList->size; i++) {
			if (current_ptr == NULL) { // the element is only one left
				free(temp_ptr->value);
				temp_ptr->value = NULL;
			}
			else{
				free(temp_ptr->value);
				temp_ptr->value = NULL;
				temp_ptr = current_ptr; //same as dequeue
				current_ptr = temp_ptr->next_node;
			}
		}
	}
	free(theList);
	theList = NULL;
}
int PCB_Queue_is_empty(PCB_Queue_p theList) {
	if (theList->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
void PCB_Queue_enqueue(PCB_Queue_p theList, PCB_p theValue) {
	if (theList != NULL&& theValue != NULL ) {
		PCB_p temp_PCB = malloc(sizeof(PCB));
		PCB_set_pid(temp_PCB, theValue->pid);
		PCB_set_state(temp_PCB, theValue->state);
		PCB_set_priority(temp_PCB, theValue->priority);
		PCB_set_pc(temp_PCB, theValue->pc);
		
		//create temp node
		struct node* temp_Node = malloc(sizeof(struct node));
		temp_Node->value = temp_PCB;
		temp_Node->next_node = NULL;

		//the first element/node of list
		if (theList->size == 0) {
			theList->first_node_ptr = temp_Node;
			theList->last_node_ptr = temp_Node;
		}
		else {
			theList->last_node_ptr->next_node = temp_Node;
			theList->last_node_ptr = temp_Node;
		}
		theList->size++; //increment size 
	 }
	else {
		printf("Error"); // either list or value was 'null'
	}
}

PCB_p PCB_Queue_dequeue(PCB_Queue_p theList){
	if (theList != NULL) {
		struct node * tempNode = theList->first_node_ptr; //grab first ele
		if (theList->size > 1) { //case more element left
			if (tempNode->next_node != NULL) {
				theList->first_node_ptr = tempNode->next_node;
				theList->size--;
			}
			PCB_p p = tempNode->value;
			free(tempNode);
			return p;
		}
		else if (theList->size == 1) {
			tempNode = theList->last_node_ptr;
			theList->first_node_ptr = NULL;
			theList->last_node_ptr = NULL;
			theList->size = 0;
			PCB_p p = tempNode->value;
			free(tempNode);
			return p;
		}
		else {
			return NULL;
		}
	}
	else {
		printf("Dequeue method got pass NULL : Error");
		return NULL;
	}
}

void PCB_Queue_toString2(PCB_Queue_p theList){
	int temp_size = theList->size;
	if (theList->size != 0) {
		printf("\nQ: Count = %d : ", theList->size);
	}
	int i = 0;
	
	for (i = 1; i <= temp_size; i++ ){
		printf("P%d ->" ,i);
	}
	printf("\n");
}

// print for check 
void PCB_Queue_toString(PCB_Queue_p theList) {
	if (theList->size != 0) {
		//char string[100];
		struct node *current_node = theList->first_node_ptr;
		while (current_node != NULL) {
			printf("PID: 0x%lX, Priority: 0x%X, State: %u, PC: 0x%lX \n", 
			PCB_get_pid(current_node->value), PCB_get_priority(current_node->value), PCB_get_state(current_node->value), PCB_get_pc(current_node->value));
			current_node = current_node->next_node;
		}
	}
}