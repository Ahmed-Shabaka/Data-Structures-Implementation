#ifndef _STACK_H_
#define _STACK_H_

#include "TYPES.h"


typedef enum 
{
	R_OK=0,
	R_NOK
}return_status_t;

typedef enum
{
	STACK_FULL=0,
	STACK_NOT_FULL,
	STACK_EMPTY,
	STACK_NOT_EMPTY
}stack_status_t;

typedef struct 
{
	void **stack;
	uint32_t stack_max_size;
	uint32_t element_count;
	sint32_t stack_top;
}stack_t;

stack_t *create_stack(uint32_t stack_max_size,return_status_t *ret_ptr);

stack_t *destroy_stack(stack_t *my_stack,return_status_t *ret_ptr);

return_status_t stack_push(stack_t *my_stack, void *stack_push_value);

void *stack_pop(stack_t *my_stack,return_status_t *ret_ptr);

void *stack_top(stack_t *my_stack,return_status_t *ret_ptr);

return_status_t stack_count(stack_t *my_stack,uint32_t *stack_size_value);

#endif