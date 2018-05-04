#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q == NULL) {
		fprintf(stderr, "queue_t pointer is pointing to null\n");
		return;
	}

	if(q->size >= MAX_QUEUE_SIZE) return;

	q->proc[q->size] = proc;
	(q->size)++;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(q == NULL) {
		fprintf(stderr, "queue_t pointer is pointing to null\n");
		return NULL;
	}

	if(q->size == 0) return NULL;
	
	// Find the highest priority element in queue
	int highestPriorityElement = 0;
	for(int i = 0; i < q->size; i++){
		if(q->proc[i]->priority > q->proc[highestPriorityElement]->priority){
			highestPriorityElement = i;
		}
	}

	// Remove the highest priority element from the queue
	q->size--;
	struct pcb_t* temp = q->proc[highestPriorityElement];
	q->proc[highestPriorityElement] = q->proc[q->size];
	
	return temp;
}

