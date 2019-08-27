#include<Stdio.h>
#include<stdlib.h>
typedef struct N
{
	int info;
	struct N *next;
}node;
void insertbeg(node**,int);
void display(node*);
void displayreverse(node*);
int main()
{
	node *head=NULL;
	display(head);
	insertbeg(&head,10);
	insertbeg(&head,20);
	insertbeg(&head,30);
	insertbeg(&head,40);
	display(head);
	printf("\nReverse List Elements Are-");
	displayreverse(head);
}

void insertbeg(node **h,int item)
{
	node*ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nError:Overflow");
		return ;
	}
	ptr->info=item;
	ptr->next=*h;
	*h=ptr;
}

void display(node*h)
{
	if(h==NULL)
	{
		printf("\nList Is Empty");
	}
	else
	{
		printf("\nList Elements Are-");
		while(h!=NULL)
		{
			printf("%5d",h->info);
			h=h->next;
		}
	}
}

void displayreverse(node*h)
{
	if(h==NULL)
	{
		return ;
	}
	else
	{
		displayreverse(h->next);
	}
	printf("%5d",h->info);
}
