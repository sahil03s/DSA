#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacknode
{
    int data;
    struct stacknode *next;
} node;

int isEmpty(node *top)
{
    return !top;
}

void push(node **top, int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = *top;
    *top = temp;
}

int pop(node **top)
{
    if(isEmpty(*top))
    {
        printf("Underflow!");
        return INT_MIN;
    }
    else
    {
        int x = (*top)->data;
        node *temp = *top;
        *top = (*top)->next;
        free(temp);
        return x;
    }
}

int peek(node *top)
{
    if(isEmpty(top))
    {
        printf("Underflow!");
        return INT_MIN;
    }
    else
        return top->data;
}
void insert_bottom(node **top, int x)
{
    if(isEmpty(*top))
        push(top,x);
    else
    {
        int temp = pop(top);
        insert_bottom(top,x);
        push(top,temp);
    }
}
void reverse(node *top)
{
    int temp;
    if(!isEmpty(top))
    {
        temp = pop(&top);
        reverse(top);
        insert_bottom(&top,temp);
    }
}

void main()
{
    node *top = NULL;
    push(&top,10);
    push(&top,0);
    push(&top,9);
    push(&top,1);
    push(&top,2);
    reverse(top);
    printf("\n%d ",pop(&top));
    printf("%d ",pop(&top));
    printf("%d ",pop(&top));
    printf("%d ",pop(&top));
    printf("%d ",pop(&top));
    
}
