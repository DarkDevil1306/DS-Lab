/*
2. Sort the given set of elements present in three stack data
structures and put them in a single stack, without using any
other variable.
CODE BY 2020ITB028_RUPAYAN_THAKUR 
*/

#include <stdio.h>

void PUSH(int *, int *);
void DISP(int * u, int v);
int POP(int* u, int *v);

void sortedInsert(int * u, int x, int* v)
{
    if (*v==-1 || x > u[*v]) {
        (*v)++ ;
        u[*v] = x;
        return;
    }
    int temp = POP(u, v);
    sortedInsert(u, x, v);
    (*v)++ ;
    u[*v] = temp;
}

void sortStack(int* u, int* v)
{
    if (*v != -1) {
        int x = POP(&u[0], v);
        sortStack(&u[0], v);
        sortedInsert(u, x, v);
    }
}

void main()
{
    int sz1, sz2, sz3;
    printf("\nENTER THE SIZE OF STACK 1: ");
    scanf("%d", &sz1);
    int stack1[sz1]; int top1= -1;
    for(int i= 0; i<sz1; i++)
        PUSH(&stack1[0], &top1);

    printf("\nENTER THE SIZE OF STACK 2: ");
    scanf("%d", &sz2);
    int stack2[sz2]; int top2= -1;
    for(int i= 0; i<sz2; i++)
        PUSH(&stack2[0], &top2);

    printf("\nENTER THE SIZE OF STACK 3: ");
    scanf("%d", &sz3);
    int stack3[sz3]; int top3= -1;
    for(int i= 0; i<sz3; i++)
        PUSH(&stack3[0], &top3);

    int t_sz= sz1+sz2+sz3;
    int t_stack[t_sz]; int t_top= -1;
    for(int i= 0; i<sz1; i++)
    {
        t_top++;
        t_stack[t_top]= POP(&stack1[0], &top1);
    }
    for(int i= 0; i<sz2; i++)
    {
        t_top++;
        t_stack[t_top]= POP(&stack2[0], &top2);
    }
    for(int i= 0; i<sz3; i++)
    {
        t_top++;
        t_stack[t_top]= POP(&stack3[0], &top3);
    }

    sortStack(&t_stack[0], &t_top);

    printf("\nTHE SORTED STACK IS : \n");
    DISP(&t_stack[0], t_top);
}

int POP(int *u, int *v)
{
    int n;
        n = u[*v];
        (*v)--;
        return n;
}

void PUSH(int *u, int *v)
{
    int n;
        printf("ENTER THE VALUE FOR THE STACK : ");
        scanf("%d", &n);
        (*v)++ ;
        u[*v] = n;
}

void DISP(int * u, int v)
{
    if( v == -1 )
        printf("STACK IS EMPTY!!!!\n");
    else
    {
        for(int i=v; i>=0; i--)
        {
            printf("|%d|\n",u[i]);
            printf("---\n");
        }
    }
}