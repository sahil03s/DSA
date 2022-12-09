#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int key;
    struct node *right;
} node;

typedef struct stack
{
    node *data;
    struct stack *next;
} stack;

stack* push(stack *top,node *data)
{
    stack *temp = (stack *)malloc(sizeof(node));
    temp->data = data;
    temp->next = top;
    top = temp;
    return top;
}

node* pop(stack **top)
{
    node *temp = (*top)->data;
    stack *p = *top;
    *top = (*top)->next;
    free(p);
    return temp;
}

node* peek(stack *top)
{
    if(!top)
        return 0;

    return top->data;
}

void insert(node **root, int key)
{
    node *prev = NULL, *p = *root;

    while(p)
    {
        prev = p;
        if(p->key == key)
        {
            printf("Element already present!\n");
            return;
        }
        else if(p->key > key)
            p = p->left;
        else if(p->key < key)
            p = p->right;
    }

    p = (node *)malloc(sizeof(node));
    p->key = key;
    p->left = p->right = 0;

    if(!*root)
        *root = p;
    else
    {
        if(prev->key > key)
            prev->left = p;
        else
            prev->right = p;
    }  
}

void create(node **root)
{
    int x = 0;
    while(x != -1)
    {
        printf("Enter data (-1 for no node) : ");
        scanf("%d",&x);
        if(x != -1)
            insert(root, x);
    }
}

void preorder(node *root)
{
    if(!root)
        return;

    stack *top = NULL;
    top = push(top, root);
    while(top)
    {
        root = pop(&top);
        printf("%d ",root->key);
        if(root->right)
            top = push(top, root->right);
        if(root->left)
            top = push(top, root->left);
        
    }
}

void inorder(node *root)
{
    if(!root)
        return;

    stack *top = NULL;
    int flag =1;
    do
    {
        while(root)
        {
            top = push(top, root);
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

    stack *top = NULL;
    do
    {
        while(root)
        {
            if(root->right)
                top = push(top, root->right);
                
            top = push(top, root);
            root = root->left;
        }
        
        root = pop(&top);

        if(root->right && root->right == peek(top))
        {
            pop(&top);
            top = push(top, root);
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
    node *root = NULL;
    create(&root);
    preorder(root);
    printf("\n\n");
    inorder(root);
    printf("\n\n");
    postorder(root);
    printf("\n\n");
}