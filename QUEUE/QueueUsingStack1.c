#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack
{
    int *arr;
    int size,top;
} stack;

stack* createstack(int n)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->top = -1;
    temp->size = n;
    temp->arr = malloc(n * sizeof(int));
    return temp;
}

void enqueue(stack *s, int x)
{
    if(s->top == s->size - 1)
    {
        printf("Overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

int dequeue(stack *s1, stack *s2)
{
    if(s1->top == -1)
    {
        printf("Underflow!\n");
        return INT_MIN;
    }

    while(s1->top != -1)
        s2->arr[++s2->top] = s1->arr[s1->top--];

    int x = s2->arr[s2->top--];

    while(s2->top != -1)
        s1->arr[++s1->top] = s2->arr[s2->top--];
    
    return x;

}

void display(stack *s)
{
    printf("\n");
    if(s->top == -1)
    {
        printf("No elements\n");
        return;
    }
    int i = s->top;
    while(i != -1)
        printf("%d ",s->arr[i--]);
    
    printf("\n");
}

void main()
{
    int opt = 0,data,n;
    printf("Enter the size of stack : ");
    scanf("%d",&n);
    stack *s1 = createstack(n);
    stack *s2 = createstack(n);
    while(opt != 4)
    {
        printf("\n1. Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nChoose an option : ");
        scanf("%d",&opt);
        while(opt < 1 || opt > 4)
        {
            printf("Choose valid option : ");
            scanf("%d",&opt);
        }
        switch(opt)
        {
            case 1 :
                printf("Enter element : ");
                scanf("%d",&data);
                enqueue(s1,data);
                break;
            case 2 :
                printf("%d is dequeued.\n",dequeue(s1,s2));
                break;
            case 3 :
                display(s1);
                break;
            case 4 :
                printf("Thank u!\n");
                break;
        }
    }
}