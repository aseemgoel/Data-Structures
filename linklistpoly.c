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
int main()
{
	node *poly=NULL;
	
	create(&poly);
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


