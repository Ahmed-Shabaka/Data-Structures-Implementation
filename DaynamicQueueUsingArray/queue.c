#include "queue.h"

static Std_ReturnType queue_full(queue_t *my_queue);
static Std_ReturnType queue_empty(queue_t *my_queue);
/**********************************************************************/
static Std_ReturnType queue_full(queue_t *my_queue)
{
	Std_ReturnType ret_status;
	if(my_queue->element_count==my_queue->queue_max_size)
		ret_status=QUEUE_FULL;
	else
		ret_status=QUEUE_NOT_FULL;
	return ret_status;
}
/**********************************************************************/
static Std_ReturnType queue_empty(queue_t *my_queue)
{
	Std_ReturnType ret_status;
	if(my_queue->element_count==0)
		ret_status=QUEUE_EMPTY;
	else
		ret_status=QUEUE_NOT_EMPTY;
	return ret_status;
}

/**********************************************************************/
queue_t *create_queue(uint32_t max_size,Std_ReturnType *ret_status)
{
	queue_t *my_queue=NULL;
	if(NULL==ret_status)
		printf("ERROR! Can't Create Queue \n");
	else
	{
		*ret_status=E_OK;
		my_queue=(queue_t *)malloc(sizeof(queue_t));
		if(NULL==my_queue)
		{
			*ret_status=E_NOT_OK;
			printf("ERROR! Can't Create Queue \n");
		}
		else
		{
			*ret_status=E_OK;
			my_queue->queue_max_size=max_size;
			my_queue->element_count=0;
			my_queue->queue_front=-1;
			my_queue->queue_rear=-1;
			my_queue->queue_array=(void **)calloc(my_queue->queue_max_size,sizeof(void *));
			if(NULL==my_queue->queue_array)
			{
				*ret_status=E_NOT_OK;
				free(my_queue);
				my_queue=NULL;
				printf("ERROR! Can't Create Queue \n");
			}
			else
			{
				*ret_status=E_OK;
				printf("Queue Created Successfully \n");
			}
		}
	}
	return my_queue;
}
/**********************************************************************/
queue_t *destroy_queue(queue_t *my_queue,Std_ReturnType *ret_status)
{
	if(NULL==ret_status)
		printf("ERROR! Can't Destroy Queue \n");
	else if(NULL==my_queue)
	{
		*ret_status=E_NOT_OK;
		printf("ERROR! Can't Destroy Queue \n");
	}
	else
	{
		*ret_status=E_OK;
		free(my_queue->queue_array);
		free(my_queue);
		my_queue=NULL;
		printf("Queue Destroied Successfully \n");
	}
	return my_queue;
}
/**********************************************************************/
Std_ReturnType enqueue_element(queue_t *my_queue,void *enqueue_value)
{
	Std_ReturnType ret_status=E_NOT_OK;
	if(NULL==my_queue || NULL==enqueue_value)
	{
		ret_status=E_NOT_OK;
		printf("ERROR! Can't Enqueue Data \n");
	}
	else if(queue_full(my_queue)==QUEUE_FULL)
	{
		ret_status=E_NOT_OK;
		printf("Queue is Full \n");
	}
	else
	{
		ret_status=E_OK;
		
		(my_queue->queue_rear)++;
		if(my_queue->element_count==0) 
			my_queue->queue_front=0;
		if(my_queue->queue_rear==my_queue->queue_max_size)  
			my_queue->queue_rear=0;
		my_queue->queue_array[my_queue->queue_rear]=enqueue_value;
		(my_queue->element_count)++;
	}
	return ret_status;
}
/**********************************************************************/
void *dequeue_element(queue_t *my_queue,Std_ReturnType *ret_status)
{
	void *dequeue_value=NULL;
	if(NULL==ret_status)
		printf("ERROR! Can't Dequeue Data \n");
	else if(NULL==my_queue)
	{
		*ret_status=E_NOT_OK;
		printf("ERROR! Can't Dequeue Data \n");
	}
	else if(queue_empty(my_queue)==QUEUE_EMPTY)
	{
		*ret_status=E_NOT_OK;
		printf("Queue is Empty \n");
	}
	else
	{
		*ret_status=E_OK;
		dequeue_value=my_queue->queue_array[my_queue->queue_front];
		(my_queue->queue_front)++;
		(my_queue->element_count)--;
		
		if(my_queue->queue_front==my_queue->queue_max_size)
			(my_queue->element_count==0)?(my_queue->queue_front=-1,my_queue->queue_rear=-1):(my_queue->queue_front=0);
	}
	return dequeue_value;
}
/**********************************************************************/
void *queue_rear(queue_t *my_queue,Std_ReturnType *ret_status)
{
	void *queue_rear_value=NULL;
	if(NULL==ret_status)
		printf("ERROR! Can't Return Rear Data \n");
	else if(NULL==my_queue)
	{
		*ret_status=E_NOT_OK;
		printf("ERROR! Can't Return Rear Data \n");
	}
	else if(queue_empty(my_queue)==QUEUE_EMPTY)
	{
		*ret_status=E_NOT_OK;
		printf("Queue is Empty \n");
	}
	else
	{
		*ret_status=E_OK;
		queue_rear_value=my_queue->queue_array[my_queue->queue_rear];
	}
	return queue_rear_value;
}
/**********************************************************************/
void *queue_front(queue_t *my_queue,Std_ReturnType *ret_status)
{
	void *queue_front_value=NULL;
	if(NULL==ret_status)
		printf("ERROR! Can't Return front Data \n");
	else if(NULL==my_queue)
	{
		*ret_status=E_NOT_OK;
		printf("ERROR! Can't Return front Data \n");
	}
	else if(queue_empty(my_queue)==QUEUE_EMPTY)
	{
		*ret_status=E_NOT_OK;
		printf("Queue is Empty \n");
	}
	else
	{
		*ret_status=E_OK;
		queue_front_value=my_queue->queue_array[my_queue->queue_front];
	}
	return queue_front_value;
}
/**********************************************************************/
Std_ReturnType queue_count(queue_t *my_queue,uint32_t *queue_size_value)
{
	Std_ReturnType ret_status=E_NOT_OK;
	if(NULL==my_queue || NULL==queue_size_value)
	{
		ret_status=E_NOT_OK;
		printf("ERROR! Can't Return Queue Size Value \n");
	}
	else
	{
		ret_status=E_OK;
		*queue_size_value=my_queue->element_count;
	}
	return ret_status;
}
/**********************************************************************/