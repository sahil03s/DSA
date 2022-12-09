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

void preorder(node *root)
{
    if(!root)
        return;

    stack *top = NULL;
    push(&top, root);
    while(top)
    {
        root = top->data;
        printf("%d ",pop(&top)->key);
        if(root->right)
            push(&top,root->right);
        if(root->left)
            push(&top,root->left);
    }
    
}

void inorder(node *root)
{
    stack *top = NULL;
    int flag = 1;
    do
    {
        while(root)
        {
            push(&top, root);
            root = root->left;
        }
        if(top)
        {
            root = pop(&top);
            printf("%d ",root->key);
            root = root->right;
        }
        else
            flag = 0;
    } while(flag);
    

}
void postorder(node *root)
{
    if(!root)
        return;
    stack *top = 0;
    do
    {
        while(root)
        {
            if(root->right)
                push(&top, root->right);

            push(&top, root);
            root = root->left;
        }
        root = pop(&top);

        if(root->right && root->right == peek(top))
        {
            pop(&top);
            push(&top, root);
            root = root->right;
        }
        else
        {
            printf("%d ",root->key);
            root = 0;
        }
    } while(top);
}

void main()
{
    node *root = 0;
    root = create();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}