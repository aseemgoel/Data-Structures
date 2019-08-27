#include<Stdio.h>
#include<stdlib.h>
typedef struct poly
{
	int coeff,int exp;
	struct N *next;
}node;
void create(node**,int,int);
void display(node*);
int main()
{
	node *poly=NULL;
	display(poly);
	create(&poly,5,2);
	create(&poly,-2,1);
	create(&poly,3,0);
	display(poly);
}

void insertbeg(node **p,int c,int e)
{
	node*ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nError:Overflow");
		return ;
	}
	ptr->coeff=c;
	ptr->exp=e;
	ptr->next=*p;
	*p=ptr;
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
			if(n>=2)
			{
				printf("\n%dx^%d",p->coeff,p->exp);
			}
			if(n=1)
			{
				printf("%dx"p->coeff);
			}
			else
			{
				printf("%d",p->coeff);
			}
			p=p->next;
		}
	}
}
