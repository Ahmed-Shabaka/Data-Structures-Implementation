#include "ll.h"

struct node *list_1=NULL;
return_status_t ret=R_NOK;

int main()
{
    uint32_t UserChoice = 0;
    uint32_t ListLength = 0;
	
    printf("-> Hello to Single Linked List \n");
    while(1)
	{
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Reverse_The_List \n");
        printf("-> 9) Reverse_Two_Nodes \n");
        printf("-> 10) Sort_The_List \n");
        printf("-> 0) Quit from application \n");
        printf("===============================\n");

        printf("\n");
		
        printf("UserChoice : ");
		fflush(stdin);
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
                ret=Insert_Node_At_Beginning(&list_1);
            break;
            case 2:
                ret=Insert_Node_At_End(&list_1);
            break;
            case 3:
                ret=Insert_Node_After(list_1);
            break;
            case 4:
                ret=Delete_Node_At_Beginning(&list_1);
            break;
            case 5:
                ret=Delete_Node(list_1);
            break;
            case 6:
                ret=Display_All_Nodes(list_1);
            break;
            case 7:
                ListLength = Get_Length(list_1,&ret);
                printf("List Length : << %i >> Nodes\n", ListLength);
            break;
			case 8:
				ret=Reverse_The_List(&list_1);
            break;
			case 9:
				ret=Reverse_Two_Nodes(list_1);
            break;
			case 10:
				ret=Sort_The_List(list_1);
            break;
            case 0:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;
}