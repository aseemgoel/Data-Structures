#include<Stdio.h>
#include<stdlib.h>
typedef struct N
{
	int info;
	struct N *next;
	struct N *prev;
}node;
void insertbeg(node**,node**,int);
void deleteafter(node**,node**,int);
void display(node*);
int main()
{
	node *head=NULL;
	node *tail=NULL;
	display(head);
	insertbeg(&head,&tail,10);
	insertbeg(&head,&tail,20);
	insertbeg(&head,&tail,30);
	insertbeg(&head,&tail,40);
	display(head);
	deleteafter(&head,&tail,20);
	display(head);
}

void insertbeg(node **h,node**t,int item)
{
	node*ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nError:Overflow");
		return ;
	}
	ptr->prev=NULL;
	ptr->info=item;
	ptr->next=*h;
	if(*h==NULL)
	{
		*h=ptr;
		*t=ptr;
	}
	else
	{
		(*h)->prev=ptr;
		*h=ptr;
	}
}

void deleteafter(node **h,node **t,int after)
{
	node *ptr;
	node *loc;
	loc=*h;
	if(loc==NULL)
	{
		return ;
	}
	ptr=loc->next;
	loc->next=ptr->next;
	if(ptr->next==NULL)
	{
		*t=loc;
	}
	else
	{
		(ptr->next)->prev=loc;
	}
	free(ptr);
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
