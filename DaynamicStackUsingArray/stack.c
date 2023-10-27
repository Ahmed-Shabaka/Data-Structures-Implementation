#include "stack.h"

static stack_status_t stack_full(stack_t *my_stack);
static stack_status_t stack_empty(stack_t *my_stack);
/***************************************************************************/
static stack_status_t stack_full(stack_t *my_stack)
{
	stack_status_t ret;

	if(my_stack->element_count==my_stack->stack_max_size)
	{
		ret=STACK_FULL;
	}
	else
	{
		ret=STACK_NOT_FULL;
	}
	return ret;
}
/***************************************************************************/
static stack_status_t stack_empty(stack_t *my_stack)
{
	stack_status_t ret;

	if(my_stack->element_count==0 && my_stack->stack_top==-1)
	{
		ret=STACK_EMPTY;
	}
	else
	{
		ret=STACK_NOT_EMPTY;
	}
	return ret;
}
/***************************************************************************/
stack_t *create_stack(uint32_t stack_max_size,return_status_t *ret_ptr)
{
	stack_t *my_stack=NULL;

	if(ret_ptr==NULL)
	{
		my_stack=NULL;
		printf("ERROR! Can't Create the Stack \n");
	}
	else
	{
		*ret_ptr=R_OK;
		my_stack=(stack_t *)malloc(sizeof(stack_t));
		if(my_stack==NULL)
		{
			*ret_ptr=R_NOK;
			my_stack=NULL;
			printf("ERROR! Can't Create the Stack \n");
		}
		else
		{
			*ret_ptr=R_OK;
			my_stack->stack_max_size=stack_max_size;
			my_stack->element_count=0;
			my_stack->stack_top=-1;
			my_stack->stack=(void **)calloc( my_stack->stack_max_size , sizeof(void *) );
			if(my_stack->stack==NULL)
			{
				free(my_stack);
				my_stack=NULL;
				*ret_ptr=R_NOK;
				printf("ERROR! Can't Create the Stack \n");
			}
			else
			{
				*ret_ptr=R_OK;
				printf("Stack Created Successfully \n");
			}
		}
	}
	return my_stack;
}
/***************************************************************************/
stack_t *destroy_stack(stack_t *my_stack,return_status_t *ret_ptr)
{
	if (ret_ptr==NULL)
	{
		printf("ERROR! Can't destroy the Stack \n");
	}
	else if(NULL==my_stack )
	{
		*ret_ptr=R_NOK;
		printf("ERROR! Can't destroy the Stack \n");
	}
	else
	{
		free(my_stack->stack);
		my_stack->stack=NULL;
		free(my_stack);
		my_stack=NULL;
		printf("Stack Destroied Successfully \n");
	}
	return my_stack;
}
/***************************************************************************/
return_status_t stack_push(stack_t *my_stack, void *stack_push_value)
{
	return_status_t ret=R_NOK;

	if(my_stack==NULL || stack_push_value==NULL || stack_full(my_stack)==STACK_FULL)
	{
		ret=R_NOK;
		printf("ERROR! Can't push to the Stack \n");
	}
	else
	{
		ret=R_OK;
		(my_stack->stack_top)++;
		my_stack->stack[my_stack->stack_top]=stack_push_value;
		(my_stack->element_count)++;
		printf("Data pushed to the Stack Successfully \n");
	}
	return ret;
}
/***************************************************************************/
void *stack_pop(stack_t *my_stack,return_status_t *ret_ptr)
{
	void *retVAL=NULL;

	if (ret_ptr==NULL)
	{
		printf("ERROR! Can't pop from the Stack \n");
	}
	else if(my_stack==NULL || stack_empty(my_stack)==STACK_EMPTY )
	{
		printf("ERROR! Can't pop from the Stack \n");
		*ret_ptr=R_NOK;
	}
	else
	{
		*ret_ptr=R_OK;
		retVAL=my_stack->stack[my_stack->stack_top];
		(my_stack->stack_top)--;
		(my_stack->element_count)--;
		printf("Data poped from the Stack Successfully \n");
	}
	return retVAL;
}
/***************************************************************************/
void *stack_top(stack_t *my_stack,return_status_t *ret_ptr)
{
	void *retVAL=NULL;

	if (ret_ptr==NULL)
	{
		printf("ERROR! Can't Display top of the Stack \n");
	}
	else if(my_stack==NULL )
	{
		printf("ERROR! Can't Display top of the Stack \n");
		*ret_ptr=R_NOK;
	}
	else if (stack_empty(my_stack)==STACK_EMPTY)
	{
		printf("The Stack is Empty \n");
	}
	else
	{
		*ret_ptr=R_OK;
		retVAL=my_stack->stack[my_stack->stack_top];
		printf("Top of the Stack Displayed Successfully \n");
	}
	return retVAL;
}
/***************************************************************************/
return_status_t stack_count(stack_t *my_stack,uint32_t *stack_size_value)
{
	return_status_t ret=R_NOK;

	if(my_stack==NULL || stack_size_value==NULL)
	{
		ret=R_NOK;
		printf("ERROR! Can't Display Size of the Stack \n");
	}
	else
	{
		ret=R_OK;
		*stack_size_value=my_stack->element_count;
		printf("Size of the Stack Displayed Successfully \n");
	}
	return ret;
}
/***************************************************************************/