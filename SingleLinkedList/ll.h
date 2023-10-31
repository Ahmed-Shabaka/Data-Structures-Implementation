#ifndef _LL_H_
#define _LL_H_

#include "TYPES.h"

typedef enum
{
	R_OK=0,
	R_NOK,
	LIST_EMPTY,
	LIST_NOT_EMPTY
}return_status_t;

struct node 
{
	uint32_t data;
	struct node *link;
};

return_status_t Insert_Node_At_Beginning(struct node **head);
return_status_t Insert_Node_At_End(struct node **head);
return_status_t Insert_Node_After(struct node *head);
return_status_t Delete_Node_At_Beginning(struct node **head);
return_status_t Delete_Node(struct node *head);
return_status_t Display_All_Nodes(struct node *head);
uint32_t Get_Length(struct node *head,return_status_t *ret);
return_status_t Reverse_The_List(struct node **head);
return_status_t Reverse_Two_Nodes(struct node *head);
return_status_t Sort_The_List(struct node *head);

#endif