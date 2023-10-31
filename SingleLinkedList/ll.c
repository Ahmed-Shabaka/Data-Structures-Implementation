#include "ll.h"

/*#####################################################################*/
return_status_t Insert_Node_At_Beginning(struct node **head)
{
	return_status_t ret= R_NOK;
	struct node *TempNode=NULL;
	
	TempNode=(struct node *)malloc(sizeof(struct node));
	if(NULL==TempNode)
	{
		ret=R_NOK;
		printf("ERROR! \n");
	}
	else
	{
		ret=R_OK;
		
		printf("Enter Data Value: ");
		scanf("%i",&(TempNode->data));
		
		if(NULL==(*head))
		{
			TempNode->link=NULL;
			(*head)=TempNode;
		}
		else
		{
			TempNode->link=(*head);
			(*head)=TempNode;
		}
	}
	return ret;
}
/*#####################################################################*/
return_status_t Insert_Node_At_End(struct node **head)
{
	return_status_t ret= R_NOK;
	struct node *TempNode=NULL;
	struct node *LastNode=NULL;
	
	TempNode=(struct node *)malloc(sizeof(struct node));
	TempNode->link=NULL;
	
	if(NULL==TempNode)
	{
		ret=R_NOK;
		printf("ERROR! \n");
	}
	else
	{
		ret=R_OK;
		
		printf("Enter Data Value: ");
		scanf("%i",&(TempNode->data));
		
		if(NULL==(*head))
		{
			(*head)=TempNode;
		}
		else
		{
			LastNode=(*head);
			while(NULL!=LastNode->link)
			{
				LastNode=LastNode->link;
			}
			LastNode->link=TempNode;
		}
	}
	return ret;
}
/*#####################################################################*/
return_status_t Insert_Node_After(struct node *head)
{
	return_status_t ret= R_NOK;
	struct node *TempNode=NULL;
	struct node *NodeListCounter=NULL;
	uint32_t NodePosition=0;
	uint32_t ListLength=1;
	uint32_t counter=1;
	
	if(head==NULL)
	{
		ret=LIST_EMPTY;
		printf("List Is Empty \n");
	}
	else
	{
		printf("Enter Node Postition(First Position is 1): ");
		scanf("%i",&(NodePosition));
		
		ListLength=Get_Length(head,&ret);
		if(NodePosition>ListLength || NodePosition<1)
		{
			ret=R_NOK;
			printf("ERROR! \n");
		}
		else
		{
			ret=R_OK;
			NodeListCounter=head;
			
			while(counter<NodePosition)
			{
				NodeListCounter=NodeListCounter->link;
				counter++;
			}
			
			TempNode=(struct node *)malloc(sizeof(struct node));
			
			if(NULL==TempNode)
			{
				ret=R_NOK;
				printf("ERROR! \n");
			}
			else
			{
				ret=R_OK;
				printf("Enter Data Value: ");
				scanf("%i",&(TempNode->data));
				
				TempNode->link=NodeListCounter->link;
				NodeListCounter->link=TempNode;
			}
		}
	}
	
	return ret;
}
/*#####################################################################*/
return_status_t Delete_Node_At_Beginning(struct node **head)
{
	return_status_t ret=R_NOK;
	struct node *TempNode=NULL;
	
	TempNode=(*head);
	
	if(NULL==(*head))
	{
		ret=LIST_EMPTY;
		printf("List Is Empty \n");
	}
	else
	{
		ret=R_OK;
		
		(*head)=TempNode->link;
		free(TempNode);
	}
	return ret;
}
/*#####################################################################*/
return_status_t Delete_Node(struct node *head)
{
	return_status_t ret= R_NOK;
	struct node *NodeListCounter=NULL;
	struct node *PrevNode=NULL;
	uint32_t NodePosition=0;
	uint32_t ListLength=1;
	uint32_t counter=1;
	
	if(head==NULL)
	{
		ret=LIST_EMPTY;
		printf("List Is Empty \n");
	}
	else
	{
		printf("Enter Node Postition(First Position is 1): ");
		scanf("%i",&(NodePosition));
		
		ListLength=Get_Length(head,&ret);
		if(NodePosition>ListLength || NodePosition<2 || ListLength==1 )
		{
			ret=R_NOK;
			printf("ERROR! \n");
		}
		else
		{
			ret=R_OK;
			PrevNode=head;
			
			while( counter<(NodePosition-1) )
			{
				PrevNode=PrevNode->link;
				counter++;
			}
			NodeListCounter=PrevNode->link;
			PrevNode->link=NodeListCounter->link;
			free(NodeListCounter);
		}
	}
	
	return ret;
}
/*#####################################################################*/
return_status_t Display_All_Nodes(struct node *head)
{
	return_status_t ret= R_NOK;
	struct node *TempNode=NULL;
	
	if(NULL==head)
	{
		ret=LIST_EMPTY;
		printf("List Is Empty \n");
	}
	else
	{
		ret=R_OK;
		TempNode=head;
		
		while(TempNode!=NULL)
		{
			printf("-> %i",TempNode->data);
			TempNode=TempNode->link;
		}
		if(NULL==TempNode) printf("-> NULL \n");
	}	
	return ret;
}
/*#####################################################################*/
uint32_t Get_Length(struct node *head,return_status_t *ret)
{
	struct node *TempNode=NULL;
	uint32_t ListLength=0;
	
	if(ret==NULL)
	{
		printf("List Is Empty \n");
	}
	else if(NULL==head)
	{
		*ret=LIST_EMPTY;
		printf("List Is Empty \n");
	}
	else
	{
		*ret=R_OK;
		TempNode=head;
		
		while(TempNode!=NULL)
		{
			ListLength++;
			TempNode=TempNode->link;
		}
	}	
	return ListLength;
}
/*#####################################################################*/
return_status_t Reverse_The_List(struct node **head)
{
	return_status_t ret=R_NOK;
	struct node *TempHead=NULL;
	struct node *LastNode=NULL;
	struct node *PrevNode=NULL;
	uint32_t ListLength=0;
	uint32_t counter=1;
	
	
	
	if(NULL==(*head))
	{
		ret=LIST_EMPTY;
		printf("List Is Empty \n");
	}
	else
	{
		ret=R_OK;
		
		ListLength=Get_Length(*head,&ret);
		
		while(ListLength-1)
		{
			PrevNode=(*head);
			while(counter<(ListLength-1))
			{
				PrevNode=PrevNode->link;
				counter++;
			}
			LastNode=PrevNode->link;
			
			LastNode->link=PrevNode;
			if(TempHead==NULL)  TempHead=LastNode;
			if(PrevNode==(*head)) 
			{
				PrevNode->link=NULL;
				(*head)=TempHead;
			}
			ListLength--;
			counter=1;
		}
	}	
	return ret;
	
}
/*#####################################################################*/
return_status_t Reverse_Two_Nodes(struct node *head)
{
	return_status_t ret=R_NOK;
	struct node *FirstNode=NULL;
	struct node *SecondNode=NULL;
	uint32_t FirstNodePosition=0;
	uint32_t SecondNodePosition=0;
	uint32_t TempValue=0;
	uint32_t ListLength=0;
	uint32_t counter=1;
	
	
	
	if(NULL==head)
	{
		ret=LIST_EMPTY;
		printf("List Is Empty \n");
	}
	else
	{
		ret=R_OK;
		ListLength=Get_Length(head,&ret);
		
		printf("Enter First Node Postition(First Position is 1): ");
		scanf("%i",&(FirstNodePosition));
		printf("Enter Second Node Postition(First Position is 1): ");
		scanf("%i",&(SecondNodePosition));
		
		if(FirstNodePosition>ListLength || SecondNodePosition>ListLength)
		{
			ret=R_NOK;
			printf("ERROR! \n");
		}
		else
		{
			FirstNode=head;
			while(counter<FirstNodePosition)
			{
				FirstNode=FirstNode->link;
				counter++;
			}
			counter=1;
			SecondNode=head;
			while(counter<SecondNodePosition)
			{
				SecondNode=SecondNode->link;
				counter++;
			}
			
			TempValue=FirstNode->data;
			FirstNode->data=SecondNode->data;
			SecondNode->data=TempValue;
		}
	}	
	return ret;
	
}
/*#####################################################################*/
return_status_t Sort_The_List(struct node *head)
{
	return_status_t ret=R_NOK;
	struct node *CurrentNode=NULL;
	struct node *NextNode=NULL;
	uint32_t TempValue=0;
	
	if(NULL==head)
	{
		ret=LIST_EMPTY;
		printf("List Is Empty \n");
	}
	else
	{
		ret=R_OK;
		
		for(CurrentNode=head;CurrentNode!=NULL;CurrentNode=CurrentNode->link)
		{
			for(NextNode=CurrentNode->link;NextNode!=NULL;NextNode=NextNode->link)
			{
				if(CurrentNode->data>NextNode->data)
				{
					TempValue=CurrentNode->data;
					CurrentNode->data=NextNode->data;
					NextNode->data=TempValue;
				}
			}
		}
		
	}
	return ret;
}
/*#####################################################################*/