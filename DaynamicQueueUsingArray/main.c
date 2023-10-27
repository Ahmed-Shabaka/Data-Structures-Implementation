#include "queue.h"

Std_ReturnType ret=E_NOT_OK;

queue_t *queue=NULL;

void *dequeue_value=NULL;
void *queue_front_value=NULL;
void *queue_rear_value=NULL;
uint32_t queue_size_value=0;

int main ()
{
	uint32_t size_scan=0;
	uint32_t Number_1=11;
	uint32_t Number_2=22;
	uint32_t Number_3=33;
	uint32_t Number_4=44;
	
	printf("=================================\n");
	printf("Enter Size of Queue: ");
	scanf("%i",&size_scan);
	queue=create_queue(size_scan,&ret);    // Enter size=3 
	printf("ret= %i \n",ret);
	printf("=================================\n");
	ret=queue_count(queue,&queue_size_value);
	printf("ret= %i \n",ret);
	printf("queue_size_value= %i \n",queue_size_value);
	printf("=================================\n");
	ret=enqueue_element(queue,&Number_1);
	printf("ret= %i \n",ret);
	printf("=================================\n");
	queue_rear_value=queue_rear(queue,&ret);
	printf("ret= %i \n",ret);
	printf("queue_rear_value= %i \n",*(sint32_t *)queue_rear_value);
	printf("=================================\n");
	queue_front_value=queue_front(queue,&ret);
	printf("ret= %i \n",ret);
	printf("queue_front_value= %i \n",*(sint32_t *)queue_front_value);
	printf("=================================\n");
	ret=enqueue_element(queue,&Number_2);
	printf("ret= %i \n",ret);
	printf("=================================\n");
	ret=enqueue_element(queue,&Number_3);
	printf("ret= %i \n",ret);
	printf("=================================\n");
	ret=enqueue_element(queue,&Number_4);
	printf("ret= %i \n",ret);
	printf("=================================\n");
    ret=queue_count(queue,&queue_size_value);
	printf("ret= %i \n",ret);
	printf("queue_size_value= %i \n",queue_size_value);
	printf("=================================\n");
	queue_rear_value=queue_rear(queue,&ret);
	printf("ret= %i \n",ret);
	printf("queue_rear_value= %i \n",*(sint32_t *)queue_rear_value);
	printf("=================================\n");
	queue_front_value=queue_front(queue,&ret);
	printf("ret= %i \n",ret);
	printf("queue_front_value= %i \n",*(sint32_t *)queue_front_value);
	printf("=================================\n");
	dequeue_value=dequeue_element(queue,&ret);
	printf("ret= %i \n",ret);
	printf("dequeue_value= %i \n",*(uint32_t *)dequeue_value);
	printf("=================================\n");
	dequeue_value=dequeue_element(queue,&ret);
	printf("ret= %i \n",ret);
	printf("dequeue_value= %i \n",*(uint32_t *)dequeue_value);
	printf("=================================\n");
	dequeue_value=dequeue_element(queue,&ret);
	printf("ret= %i \n",ret);
	printf("dequeue_value= %i \n",*(uint32_t *)dequeue_value);
	printf("=================================\n");
	dequeue_value=dequeue_element(queue,&ret);
	printf("ret= %i \n",ret);
	//printf("dequeue_value= %i \n",*(uint32_t *)dequeue_value);    // Accessing NULL Pointer (returned from dequeue_element function) Causing Run-time Error
	printf("=================================\n");
	queue_rear_value=queue_rear(queue,&ret);
	printf("ret= %i \n",ret);
	//printf("queue_rear_value= %i \n",*(sint32_t *)queue_rear_value);
	printf("=================================\n");
	queue_front_value=queue_front(queue,&ret);
	printf("ret= %i \n",ret);
	//printf("queue_front_value= %i \n",*(sint32_t *)queue_front_value);
	printf("=================================\n");
	ret=queue_count(queue,&queue_size_value);
	printf("ret= %i \n",ret);
	printf("queue_size_value= %i \n",queue_size_value);	
	printf("=================================\n");
	queue=destroy_queue(queue,&ret);
	printf("ret= %i \n",ret);
	printf("=================================\n");
	
	return ZERO;
}