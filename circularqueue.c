#include<stdio.h>
#define N 5
typedef struct
{
	int a[N];
	int front,rear;
}queue;
void insert(queue*,int);
void remove1(queue*);
void display(queue*);

int main()
{
	queue s;
	int choice,item;
	s.front=-1;
	s.rear=-1;
	
	do
	{
		printf("\n1:Insert");
		printf("\n2:Delete");
		printf("\n3:Display");
		printf("\n4:Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					printf("\nEnter Element: ");
					scanf("%d",&item);
					insert(&s,item);
					break;
			case 2:
					remove1(&s);
					break;
			case 3:
					display(&s);
					break;
			case 4: 
					break;
			default:
					printf("\nError:Invalid Choice");
		}
	}while(choice!=4);
}
	
void insert(queue*p,int item)
{
	if(((p->rear)+1==p->front)||(p->front==0&&p->rear==N-1))
	{
		printf("\nError:Overflow");
	}
	else
	{
		p->rear=(p->rear+1)%N;
		p->a[(p->rear)]=item;
		if(p->front==-1)
		{
			p->front=p->front+1;
		}
	}	
}

void remove1(queue*p)
{
	if(p->front==-1)
	{
		printf("\nError:Underflow");
	}
	else
	{
		printf("\nItem Deleted:%d",p->a[p->front]);
		if(p->front==p->rear)
		{
			p->front=-1;
			p->rear=-1;
		}
		else
		{
			p->front=(p->front+1)%N;
			
		}
	}
}

void display(queue*p)
{
	int i;
	if(p->front==-1)
	{
		printf("\nQueue Is Empty");
	}
	else
	{
		printf("\nQueue Elements Are: ");
		for(i=p->front;i!=p->rear;i=(i+1)%N)
		{
			printf("%5d",p->a[i]);
		}
		printf("%5d",p->a[i]);
	}
}


