#ifndef _STACK_H_
#define _STACK_H_

#include "TYPES.h"

#define STACK_MAX_SIZE  5


typedef enum 
{
	R_OK=0,
	R_NOK=1
}return_status_t;

typedef enum 
{
	STACK_EMPTY=0,
	STACK_NOT_EMPTY=1,
	STACK_FULL=2,
	STACK_NOT_FULL=3
}stack_status_t;

typedef struct
{
	uint32 data[STACK_MAX_SIZE];
	sint32 stack_pointer;
}stack_t;

return_status_t stack_init(stack_t *my_stack);

return_status_t stack_push(stack_t *my_stack,uint32 value);

return_status_t stack_pop(stack_t *my_stack,uint32 *stack_pop_value);

return_status_t stack_top(stack_t *my_stack,uint32 *stack_top_value);

return_status_t stack_size(stack_t *my_stack,uint32 *stack_size_value);

return_status_t stack_display(stack_t *my_stack);



#endif