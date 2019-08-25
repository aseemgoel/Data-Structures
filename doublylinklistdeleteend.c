#include<Stdio.h>
#include<stdlib.h>
typedef struct N
{
	int info;
	struct N *next;
	struct N *prev;
}node;
void insertbeg(node**,node**,int);
void deletebeg(node**,node**);
void deleteend(node**,node**);
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
	deletebeg(&head,&tail);
	display(head);
	deleteend(&head,&tail);
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


void deletebeg(node **h,node **t)
{
	node *ptr;
	if(*h==NULL)
	{
		printf("\nError:Underflow");
		return ;
	}
	ptr=*h;
	if(*h==*t)
	{
		*h=NULL;
		*t=NULL;
	}
	else
	{
		((*h)->next)->prev=NULL;
		*h=(*h)->next;
	}
	free(ptr);
}

void deleteend(node **h,node **t)
{
	node *ptr;
	if(*h==NULL)
	{
		printf("\nError:Underflow");
		return ;
	}
	ptr=*t;
	if(*h==*t)
	{
		*h=NULL;
		*t=NULL;
	}
	else
	{
		((*t)->prev)->next=NULL;
		*t=(*t)->prev;
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
