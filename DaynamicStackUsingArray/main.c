#include "stack.h"

stack_t *stack=NULL;
return_status_t ret=R_NOK;
void *stack_pop_value=NULL;
void *stack_top_value=NULL;
uint32_t stack_size_value=0;

int main()
{
	uint32_t var1=11;
	uint8_t var2='Y';
	float32_t var3=22.22;
	uint16_t var4=33;

	stack=create_stack(3,&ret);
	printf("ret= %i \n",ret);
	printf("stack= %x \n",stack);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->stack_max_size= %i \n",stack->stack_max_size);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack= %x \n",stack->stack);
	printf("====================================\n");
	ret=stack_push(stack,&var1);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack[stack->stack_top]= %i \n",*(uint32_t *)(stack->stack[stack->stack_top]) );
	printf("====================================\n");
	ret=stack_push(stack,&var2);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack[stack->stack_top]= %c \n",*(uint8_t *)(stack->stack[stack->stack_top]));
	printf("====================================\n");
	ret=stack_push(stack,&var3);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack[stack->stack_top]= %f \n",*(float32_t *)(stack->stack[stack->stack_top]));
	printf("====================================\n");
	ret=stack_push(stack,&var4);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack[stack->stack_top]= %f \n",*(float32_t *)(stack->stack[stack->stack_top]));
	printf("====================================\n");
	stack_top_value=stack_top(stack,&ret);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack[stack->stack_top]= %f \n",*(float32_t *)(stack->stack[stack->stack_top]));
	printf("stack_top_value= %f \n",*(float32_t *)stack_top_value);
	printf("====================================\n");
	ret=stack_count(stack,&stack_size_value);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack[stack->stack_top]= %f \n",*(float32_t *)(stack->stack[stack->stack_top]));
	printf("stack_size_value= %i \n",stack_size_value);
	printf("====================================\n");
	stack_pop_value=stack_pop(stack,&ret);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack[stack->stack_top]= %c \n",*(uint8_t *)(stack->stack[stack->stack_top]));
	printf("stack_pop_value= %f \n",*(float32_t *)stack_pop_value);
	printf("====================================\n");
	stack_pop_value=stack_pop(stack,&ret);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack->stack[stack->stack_top]= %i \n",*(uint32_t *)(stack->stack[stack->stack_top]));
	printf("stack_pop_value= %c \n",*(uint8_t *)stack_pop_value);
	printf("====================================\n");
	stack_pop_value=stack_pop(stack,&ret);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack_pop_value= %i \n",*(uint32_t *)stack_pop_value);
	printf("====================================\n");
	stack_top_value=stack_top(stack,&ret);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("====================================\n");
	stack_pop_value=stack_pop(stack,&ret);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("====================================\n");
	ret=stack_count(stack,&stack_size_value);
	printf("ret= %i \n",ret);
	printf("stack->stack_top= %i \n",stack->stack_top);
	printf("stack->element_count= %i \n",stack->element_count);
	printf("stack_size_value= %i \n",stack_size_value);
	printf("====================================\n");
	stack=destroy_stack(stack,&ret);
	printf("ret= %i \n",ret);
	printf("stack= %x \n",stack);
	printf("====================================\n");

	return ZERO;
}



