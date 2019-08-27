#include<Stdio.h>
#include<stdlib.h>
typedef struct poly
{
	int coeff;
	int exp;
	struct poly *next;
}node;
void create(node**);
void display(node*);
void mulpoly(node*,node*,node**);
int main()
{
	node *poly1=NULL;
	node *poly2=NULL;
	node *poly3=NULL;
	printf("\nEnter First Polynomial");
	create(&poly1);
	display(poly1);
	printf("\nEnter Second Polynomial");
	create(&poly2);
	display(poly2);
	mulpoly(poly1,poly2,&poly3);
	display(poly3);
}

void create(node **p)
{
	char choice;
	int c,e;
	
	printf("\nEnter polynomial in ascending order of exponent\n");
	do
	{
		node*ptr=(node*)malloc(sizeof(node));
		if(ptr==NULL)
		{
			printf("\nError:Overflow");
			return ;
		}
		printf("\nEnter coefficient and exponent : ");
		scanf("%d %d",&c,&e);
		ptr->coeff=c;
		ptr->exp=e;
		ptr->next=*p;
		*p=ptr;
		printf("\nEnter y to continue....");
		choice = getch();
	}while(choice=='y'|| choice=='Y');
}

void display(node*p)
{
	if(p==NULL)
	{
		printf("\nNo Data:");
	}
	else
	{
		printf("\nPolynomial Is-");
		while(p!=NULL)
		{
			if(p->coeff>0)
				printf(" + ");
			if(p->exp>=2)
			{
				printf(" %dx^%d",p->coeff,p->exp);
			}
			else if(p->exp==1)
			{
				printf("  %dx",p->coeff);
			}
			else
			{ 
				printf(" %d",p->coeff);
			}
			p=p->next;
		}
	}
}

void mulpoly(node *p1,node *p2,node **p3)
{
	int c,e;
	node *temp,*ptr;									
	while(p1!=NULL)
	{
		temp=p2;
		while(temp!=NULL)
		{
			c=p1->coeff*temp->coeff;
			e=p1->exp+temp->exp;
			ptr=*p3;
			while(ptr!=NULL)
			{
				if(ptr->exp==e)
				{
					break;
				}
				ptr=ptr->next;
			}
			if(ptr==NULL)
			{
				node * p=(node*)malloc(sizeof(node)); 
				p->coeff = c;
				p->exp = e;
				p->next=*p3;
				*p3=p;
				//create(p3);
			}
			else
			{
				ptr->coeff+=c;
			}
			temp=temp->next;
		}
		p1=p1->next;
	}
}
