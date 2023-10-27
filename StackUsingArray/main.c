#include "stack.h"

stack_t stack1;
stack_t stack2;


int main()
{
	return_status_t ret=R_NOK;
	uint32 stack_pop_value;
	uint32 stack_top_value;
	uint32 stack_size_value;
	
	ret= stack_init(&stack1);
	if(R_NOK==ret)
	{
		printf("Stack1 Failed to be Initialized! \n");
	}
	else
	{
		ret= stack_push(&stack1,11);
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_push(&stack1,22);
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_push(&stack1,33);
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_push(&stack1,44);
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_push(&stack1,55);
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_size(&stack1,&stack_size_value);
		if(R_OK==ret)
		{
			printf("stack_size_value= %i\n",stack_size_value);
		}
		printf("===================================\n");
		ret= stack_display(&stack1);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_push(&stack1,66);
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_push(&stack1,77);
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_pop(&stack1,&stack_pop_value);
		if(R_OK==ret)
		{
			printf("stack_pop_value= %i\n",stack_pop_value);
		}
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_pop(&stack1,&stack_pop_value);
		if(R_OK==ret)
		{
			printf("stack_pop_value= %i\n",stack_pop_value);
		}
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_pop(&stack1,&stack_pop_value);
		if(R_OK==ret)
		{
			printf("stack_pop_value= %i\n",stack_pop_value);
		}
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_pop(&stack1,&stack_pop_value);
		if(R_OK==ret)
		{
			printf("stack_pop_value= %i\n",stack_pop_value);
		}
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_pop(&stack1,&stack_pop_value);
		if(R_OK==ret)
		{
			printf("stack_pop_value= %i\n",stack_pop_value);
		}
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_pop(&stack1,&stack_pop_value);
		if(R_OK==ret)
		{
			printf("stack_pop_value= %i\n",stack_pop_value);
		}
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		
		printf("===================================\n");
		ret= stack_push(&stack1,99);
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret=stack_top(&stack1,&stack_top_value);
		if(R_OK==ret)
		{
			printf("stack_top_value= %i\n",stack_top_value);
		}
		printf("return_status_t= %i\n",ret);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
		printf("===================================\n");
		ret= stack_size(&stack1,&stack_size_value);
		if(R_OK==ret)
		{
			printf("stack_size_value= %i\n",stack_size_value);
		}
		printf("===================================\n");
		ret= stack_display(&stack1);
		printf("Stack Pointer of Stack1 = %i \n",stack1.stack_pointer);
	}
	
	ret= stack_init(&stack2);
	if(R_NOK==ret)
	{
		printf("Stack2 Failed to be Initialized! \n");
	}
	
	
	
	
	return 0;
}