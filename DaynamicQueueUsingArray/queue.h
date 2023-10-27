#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "TYPES.h"

typedef struct 
{
	void **queue_array;
	uint32_t element_count;
	uint32_t queue_max_size;
	sint32_t queue_rear;        // last element entered the queue
	sint32_t queue_front;       // first element entered the queue
}queue_t;

queue_t *create_queue(uint32_t max_size,Std_ReturnType *ret_status);

queue_t *destroy_queue(queue_t *my_queue,Std_ReturnType *ret_status);

Std_ReturnType enqueue_element(queue_t *my_queue,void *enqueue_value);

void *dequeue_element(queue_t *my_queue,Std_ReturnType *ret_status);

void *queue_rear(queue_t *my_queue,Std_ReturnType *ret_status);

void *queue_front(queue_t *my_queue,Std_ReturnType *ret_status);

Std_ReturnType queue_count(queue_t *my_queue,uint32_t *queue_size_value);


#endif