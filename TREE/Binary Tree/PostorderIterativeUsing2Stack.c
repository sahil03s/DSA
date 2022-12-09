#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    struct node *left;
    int key;
    struct node *right;
} node;

typedef struct stack
{
    struct node *data;
    struct stack *next;
} stack;

void push(stack **top, node *x)
{
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = x;
    temp->next = *top;
    *top = temp;   
}

node* pop(stack **top)
{
    if(!*top)
    {
        printf("Underflow!\n");
        return 0;
    }
    node *x = (*top)->data;
    stack *temp = *top;
    *top = (*top)->next;
    free(temp);
    return x;
}

node *peek(stack *top)
{
    if(top)
        return top->data;

    else
        return 0;
}

node *create()
{
    int x;
    printf("Enter data (-1 for no node) : ");
    scanf("%d",&x);
    if(x == -1)
        return 0;
    node *temp = (node *)malloc(sizeof(node));
    if(!temp)
        return 0;
    temp->key = x;
    printf("Enter left child of %d :\n",x);
    temp->left = create();
    printf("Enter right child of %d :\n",x);
    temp->right = create();
    return temp;
}

void postorder(node *root)
{
    if(!root)
        return;
    stack *top1 = 0, *top2 = 0;
    push(&top1, root);
    while(top1)
    {
        push(&top2, pop(&top1));
        if(peek(top2)->left)
            push(&top1, peek(top2)->left);
        if(peek(top2)->right)
            push(&top1, peek(top2)->right);
    }
    while(top2)
    {
        printf("%d ",pop(&top2)->key);
    }
}

void main()
{
    node *root = 0;
    root = create();
    printf("Postorder :\n");
    postorder(root);
    printf("\n");
}