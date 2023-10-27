#include "stack.h"

static stack_status_t stack_full(stack_t *my_stack);
static stack_status_t stack_empty(stack_t *my_stack);


static stack_status_t stack_full(stack_t *my_stack)
{
	if (my_stack->stack_pointer == STACK_MAX_SIZE-1 )
	{
		return STACK_FULL;
	}
	else
	{
		return STACK_NOT_FULL;
	}
}

/* =================================================== */
static stack_status_t stack_empty(stack_t *my_stack)
{
	if (my_stack->stack_pointer == -1 )
	{
		return STACK_EMPTY;
	}
	else
	{
		return STACK_NOT_EMPTY;
	}
}
/* =================================================== */

/*
*  
	@brief   initialize the stack pointer
	@param   my_stack  pointer to the stack
	@ret_val status of the initialization processs
*/
return_status_t stack_init(stack_t *my_stack)
{
	return_status_t ret=R_NOK;
	if (NULL==my_stack)
	{
		ret=R_NOK;
	}
	else
	{
		my_stack->stack_pointer= -1;
		ret=R_OK;
	}
	return ret;
}
/* =================================================== */

return_status_t stack_push(stack_t *my_stack,uint32 value)
{
	return_status_t ret= R_NOK;
	
	if( ( NULL == my_stack ) || ( stack_full(my_stack)==STACK_FULL ) )
	{
		ret=R_NOK;
		printf("ERROR! Can't push Value (%i) \n",value);
	}
	else
	{
		my_stack->stack_pointer++;
		my_stack->data[my_stack->stack_pointer]=value;
		printf("Value ( %i ) Pushed to the stack \n",my_stack->data[my_stack->stack_pointer]);
		ret= R_OK;
	}
	return ret;
}
/* =================================================== */
return_status_t stack_pop(stack_t *my_stack,uint32 *stack_pop_value)
{
	return_status_t ret=R_NOK;
	if( ( NULL == my_stack ) || ( stack_empty(my_stack)==STACK_EMPTY ) || ( NULL==stack_pop_value) )
	{
		ret=R_NOK;
		printf("ERROR! Can't pop anything from the stack \n");
	}
	else
	{
		*stack_pop_value=my_stack->data[my_stack->stack_pointer];
		my_stack->stack_pointer--;
		printf("Value ( %i ) poped from the stack \n",*stack_pop_value);
		ret= R_OK;
	}
	return ret;
}
/* =================================================== */
return_status_t stack_top(stack_t *my_stack,uint32 *stack_top_value)
{
	
	return_status_t ret=R_NOK;
	if (NULL==my_stack || ( stack_empty(my_stack)==STACK_EMPTY ) || ( NULL==stack_top_value) )
	{
		ret=R_NOK;
		printf("ERROR! Can not display top of the stack \n");
	}
	else
	{
		*stack_top_value=my_stack->data[my_stack->stack_pointer];
		ret=R_OK;
	}
	return ret;
	
}
/* =================================================== */
return_status_t stack_size(stack_t *my_stack,uint32 *stack_size_value)
{
	
	return_status_t ret=R_NOK;
	if (NULL==my_stack || ( stack_empty(my_stack)==STACK_EMPTY ) || ( NULL==stack_size_value) )
	{
		ret=R_NOK;
		printf("ERROR! Can not display size of the stack \n");
	}
	else
	{
		*stack_size_value = my_stack->stack_pointer + 1;
		ret=R_OK;
	}
	return ret;
	
}
/* =================================================== */
return_status_t stack_display(stack_t *my_stack)
{
	sint32 counter=ZERO;
	return_status_t ret=R_NOK;
	if (NULL==my_stack || ( stack_empty(my_stack)==STACK_EMPTY ) )
	{
		ret=R_NOK;
		printf("ERROR! Can not display elements of the stack \n");
	}
	else
	{
		printf("Stack data : \n");
		for(counter=my_stack->stack_pointer;counter>=0;counter--)
		{
			printf("%i\t",my_stack->data[counter]);
		}
		printf("\n");
		ret=R_OK;
	}
	return ret;
}

