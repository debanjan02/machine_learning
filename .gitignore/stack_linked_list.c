#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void push(struct node **top, int data)
{
	printf("--------");
	if(*top==NULL)
	{
		struct node *tmp;
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->data=data;
		tmp->link=NULL;
		*top=tmp;
	}
	else 
	{
		struct node *tmp;
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->data=data;
		tmp->link=*top;
		*top=tmp;
	}
}

int pop(struct node **top,struct node *ptr)
{
	int element;
	if(*top==NULL)
	{
		printf("The stack is empty\n");
	}
	else
	{
		element=ptr->data;
		*top=ptr->link;
		printf("%d popped\n",element);
	}
}

void display(struct node **top,struct node *ptr)
{
	if(*top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		if(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			display(top,ptr->link);
		}
	}
}
int main()
{
	struct node *top=NULL;
	int choice, element;
	while(1)
    {
        printf("------STACK OPERATION---------------------\n\n");
        printf("------------------------------------------\n");
        printf("      1    -->    PUSH               \n");
        printf("      2    -->    POP               \n");
        printf("      3    -->    DISPLAY               \n");
        printf("      4    -->    EXIT           \n");
        printf("------------------------------------------\n");
        printf("Enter the choice : ");

        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
				printf("Enter the element to be pushed : ");
				scanf("%d",&element);
                push(&top,element);
                break;

            case 2:
				pop(&top,top);
				break;

			case 3:
				display(&top,top);
				break;

			case 4:
				exit(0);
				break;

			default:
				printf("Invalid choice!\n");
		}
	}
    return 0;
}
