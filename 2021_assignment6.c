/*******
Assignment 6: Polynomial Addition Using Linked List
Author: Harish Gautam
Roll No.: 2021
Program: WAP to read two polynomials from the user, save them in two different linked lists and add them in a third linked list.
*******/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coeff;  //coefficient
	int power;
	struct node *next;
};

typedef struct node nd;

void readpolynomial(nd** head)
{
        int coeff,pow;
	int count;
	nd *new_node=(nd *)malloc(sizeof(nd));
	*head = new_node;
	do{
		printf("\n Please Enter Coeffecient: ");
		scanf("%d", &coeff);
		printf("\n Please Enter power of the coeffecient: ");
		scanf("%d",&pow);
		new_node->coeff = coeff;
		new_node->power = pow;
		new_node->next = NULL;
		printf("\nDo you want to enter more terms? Then please enter 1 for Yes and 0 for No:");
		scanf("%d",&count);
		if(count)
		{
			new_node->next = (nd*)malloc(sizeof(nd*));
			new_node = new_node->next;
			new_node->next  = NULL;
		}
	     }while(count);
}

void display_polynomial(nd* head)
{
	//printf("\n Result of Entered Polynomial Expression is:\n");
	while(head != NULL)
	{
		printf("%dx^%d", head->coeff, head->power);
		head = head->next;
		if(head !=NULL)
			printf("+");
	}
}

void add_polynomials(nd** result, nd* first_poly, nd* second_poly)
{
	nd* new_node = (nd*)malloc(sizeof(nd));
	new_node->next = NULL;
	*result = new_node;
	while(first_poly && second_poly)
	{
		if(first_poly->power > second_poly->power)
		{
			new_node->coeff = first_poly->coeff;
			new_node->power = first_poly->power;
			first_poly = first_poly->next;
		}
		else if(first_poly->power < second_poly->power)
		{
			new_node->coeff = second_poly->coeff;
			new_node->power = second_poly->power;
			second_poly = second_poly->next;
		}
		else
		{
			new_node->coeff = first_poly->coeff + second_poly->coeff;
			new_node->power = first_poly->power;
			first_poly = first_poly->next;
			second_poly = second_poly->next;
		}
		
		if(first_poly && second_poly)
		{
		new_node->next = (nd *)malloc(sizeof(nd));
 			new_node = new_node->next;
 			new_node->next = NULL;
 		}
 	}
 	while(first_poly || second_poly)
 	{
 		new_node->next = (nd *)malloc(sizeof(nd));
 		new_node = new_node->next;
 		new_node->next = NULL;
 			
 		if(first_poly)
 		{
 			new_node->coeff = first_poly->coeff;
 			new_node->power = first_poly->power;
 			first_poly = first_poly->next;
 		}

 		else if(second_poly)
 		{
 			new_node->coeff = second_poly->coeff;
 			new_node->power = second_poly->power;
 			second_poly = second_poly->next;
 		}
 	}
 }
 
int main()
{

	nd* first_poly = NULL;
	nd* second_poly = NULL;
	nd* result = NULL;

	printf("\nEnter the corresponding data to get expression of polynomial:-\n");
	printf("\nPlease Enter Data for First polynomial:\n");
	readpolynomial(&first_poly);
	printf("\nfirst polynomial term is: \n");
	display_polynomial(first_poly);
	printf("\nPlease Enter Data for Second polynomial:\n");
	readpolynomial(&second_poly);
	printf("\nsecond polynomial term is: \n");
	display_polynomial(second_poly);
	add_polynomials(&result, first_poly, second_poly);
	printf("\nResult of Added polynomial: ");
	display_polynomial(result);
	return 0;
}
