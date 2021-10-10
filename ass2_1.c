/*
1. Write a method duplicate Stack that returns a new stack
containing the same elements and in the same order as the
stack specified in the parameter. The method should create a
new stack and fill it with the same data elements as the given
stack. (You do not need to duplicate the contents of the
elements.).Before the method finishes, it must restore the
contents of the original stack to its original state (same
contents in the same order).
CODE BY 2020ITB028_RUPAYAN_THAKUR 
*/

#include <stdio.h>

int POP(int *a, int *b)
{
    int n;int abj;
        n = a[*b];
        (*b)--;
        return n;
}

void PUSH(int *a, int *b)
{
    int n;
        printf("ENTER THE VALUE FOR THE STACK :  ");
        scanf("%d", &n);
        (*b)++ ;
        a[*b] = n;
}

void DISP(int * a, int b)
{
    if( b == -1 )
        printf("ERROR! STACK IS EMPTY!!!!\n");
    else
    {
        for(int i=b; i>=0; i--)
        {
            printf("|%d|\n",a[i]);
            printf("---\n");
        }
    }
}

void duplicateStack(int* a, int* b, int size)
{
    int stack1[size]; int stack2[size];
    int top1= -1; int top2= -1; int temp= *b;
    for(int i= 0; i<size; i++)
    {
        top1++;
        stack1[top1]= POP(&a[0], b);
    }

    for(int i= 0; i<size; i++)
    {
        top2++;
        stack2[top2]= POP(&stack1[0], &top1);
    }
    	*b= temp;
printf("\nTHE DUPLICATE STACK IS : \n\n");
    	DISP(&stack2[0], top2);
}

int main()
{
    int sz;
    printf("\nENTER THE SIZE OF THE STACK : \n");
    scanf("%d", &sz);
    int stack[sz]; int top= -1;
    for(int i= 0; i<sz; i++)
        PUSH(&stack[0], &top);
    
    	printf("\nTHE ORIGINAL STACK IS : \n\n");
DISP(&stack[0], top);
duplicateStack(&stack[0], &top, sz);
}