#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Stack
{
    int top;
    unsigned size;
    int *array;
} st;

st* createstack(unsigned capacity)
{
    st* stack = (st *)malloc(sizeof(st));
    if(!stack)
        return NULL;
    
    stack->top = -1;
    stack->size = capacity;
    stack->array = (int *)malloc(stack->size * sizeof(int));

    return stack;
}

int isEmpty(st *stack)
{
    return stack->top == -1;
}

int isFull(st *stack)
{
    return stack->top == stack->size-1;
}

void push(st *stack, int x)
{
    if(isFull(stack))
    {
        printf("Overflow!");
        return;
    }
    else
        stack->array[++stack->top] = x;
}

int pop(st *stack)
{
    if(isEmpty(stack))
    {
        printf("Underflow!");
        return INT_MIN;
    }
    else
        return stack->array[stack->top--];
}

int peek(st *stack)
{
    if(isEmpty(stack))
    {
        printf("Underflow!");
        return INT_MIN;
    }
    else
        return stack->array[stack->top];
}

char* reverse(char *s)
{
    st *stack = createstack(strlen(s));
    char *str = (char *)malloc(strlen(s));
    if(!stack && !str)
        return NULL;

    int i = 0, k = -1;
    while(s[i])
    {
        push(stack, s[i++]);
    }
    while(!isEmpty(stack))
    {
        str[++k] = pop(stack);
    }
    str[++k] = '\0';
    return str;
}

void main()
{
    char name[20];
    printf("Enter a string :");
    scanf("%[^\n]s",name);
    char *r = reverse(name);
    printf("\nString Entered is : %s",name);
    printf("\nString Entered is : %s",r);
}
