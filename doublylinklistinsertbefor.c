#include<Stdio.h>
#include<stdlib.h>
typedef struct N
{
	int info;
	struct N *next;
	struct N *prev;
}node;
void insertbeg(node**,node**,int);
void insertbefore(node**,node*,int,int);
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
	insertbefore(&head,tail,30,35);
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


void insertbefore(node **h,node*t,int before,int item)
{
	node *loc;
	node*ptr=(node*)malloc(sizeof(node));
	if(h==NULL)
	{
		return ;
	}
	loc=*h;
	while(loc!=NULL&&loc->info!=before)
	
	{
		loc=loc->next;
	}
	if(loc==NULL)
	{
		return ;
	}
	ptr->next=loc;
	ptr->info=item;
	ptr->prev=loc->prev;
	if(*h==loc)
	{
		*h=ptr;
	}
	else
	{
		(loc->prev)->next=ptr;
	}
	loc->prev=ptr;
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
