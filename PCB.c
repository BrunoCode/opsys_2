#include "PCB.h"
#include <stdlib.h>
#include <stdio.h>

PCB_p PCB_construct(void) {
	return malloc(sizeof(PCB));
}

void PCB_destruct(PCB_p p) {
	free(p);
}

void PCB_init(PCB_p p) {
	if (p == NULL) return;
	PCB_set_pid(p, 0);
	PCB_set_state(p, PCB_STATE_NEW);
	PCB_set_priority(p, PCB_PRIORITY_MAX);
	PCB_set_pc(p, 4294000000);
}

void PCB_set_pid(PCB_p p, unsigned long pid) {
	if (p == NULL) return;
	p->pid = pid;
}

void PCB_set_state(PCB_p p, enum PCB_STATE_TYPE state) {
	if (p == NULL) return;
	if (state < 0 || state >= PCB_STATE_LAST_ERROR) return;
	p->state = state;
}

void PCB_set_priority(PCB_p p, unsigned short priority) {
	if (p == NULL) return;
	if (priority > PCB_PRIORITY_MAX) return;
	p->priority = priority;
}

void PCB_set_pc(PCB_p p, unsigned long pc) {
	if (p == NULL) return;
	p->pc = pc;
}

unsigned long PCB_get_pid(PCB_p p) {
	if (p == NULL) return 0;
	return p->pid;
}  

enum PCB_STATE_TYPE PCB_get_state(PCB_p p) {
	if (p == NULL) return 0;
	return p->state;
}

unsigned short PCB_get_priority(PCB_p p) {
	if (p == NULL) return 0;
	return p->priority;
}

unsigned long PCB_get_pc(PCB_p p) {
	if (p == NULL) return 0;
	return p->pc;
} 

void PCB_toString(PCB_p p, char *s) {
	if (p == NULL || s == NULL) return;
	sprintf(s, "PID: 0x%lX, Priority: 0x%X, State: %u, PC: 0x%lX", 
			PCB_get_pid(p), PCB_get_priority(p), PCB_get_state(p), PCB_get_pc(p));
	return;
}
