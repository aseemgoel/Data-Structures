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
void addpoly(node*,node*,node**);
int main()
{
	node *poly1=NULL;
	node *poly2=NULL;
	node *poly3=NULL;
	printf("\nEnter First Polynomial");
	create(&poly1);
	display(poly1);
	printf("\nEnt8er Second Polynomial");
	create(&poly2);
	display(poly2);
	addpoly(poly1,poly2,&poly3);
	display(poly);
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
			else if(p->exp=1)
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

void addpoly(node *p1,node *p2,node **p3)
{
	int c,e;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->exp>p2->exp)
		{
			p1->coeff=c;
			p1->exp=e;
			p1->next=p1;
		}
		else if(p1->exp<p2->exp)
		{
			p2->coeff=c;
			p2->exp=e;
			p2->next=p2;
		}
		else
		{
			(p1->coeff+p2->coeff)=c;
			p1->exp=e;
			p1->next=p1;
			p2->next=p2;
		}
		node*ptr=(node*)malloc(sizeof(node));
		ptr=ptr->next;
		ptr->next=NULL;
	}
		while(p1!=NULL||p2!=NULL)
		{
			if(p1!=null)
			{
				p1->exp=e;
				p1->coeff=c;
				p1=p1->next;
			}
			if(p2!=null)
			{
				p2->exp=e;
				p2->coeff=c;
				p2=p2->next;
			}
			node*ptr=(node*)malloc(sizeof(node));
			ptr=ptr->next;
			ptr->next=NULL;
		}
}
