#include<Stdio.h>
#include<stdlib.h>
typedef struct N
{
	int info;
	struct N *next;
}node;
void insertbeg(node**,int);
void insertend(node**,int);
void deletebeg(node**);
void display(node*);
int main()
{
	node *head=NULL;
	display(head);
	insertbeg(&head,10);
	insertbeg(&head,20);
	insertbeg(&head,30);
	insertbeg(&head,40);
	display(head);
	insertend(&head,50);
	display(head);
	deletebeg(&head);
	display(head);
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

void insertend(node**h,int item)
{
	node*ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nError:Overflow");
		return ;
	}
	ptr->info=item;
	ptr->next=NULL;
	if(*h==NULL)
	{
		*h=ptr;
	}
	else
	{
		node*p=*h;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=ptr;
	}
}

void deletebeg(node **h)
{
	node *ptr;
	if(*h==NULL)
	{
		printf("\nError:Underflow");
		return ;
	}
	ptr=*h;
	*h=ptr->next;
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
