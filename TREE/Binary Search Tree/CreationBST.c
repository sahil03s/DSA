#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int key;
    struct node *left, *right;
} node;

int height(node *root);
node* in_pre(node *root);
node* in_suc(node *root);
node* insert(node *root, int data);
void create(node **root);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
node* delete(node *root, int data);


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

    int data = 0;
    while(data != -1)
    {
        printf("Enter data to be deleted (-1 for no node): ");
        scanf("%d",&data);
        if(data != -1)
            root = delete(root, data);
    }
    
    preorder(root);
    printf("\n\n");
    inorder(root);
    printf("\n\n");
    postorder(root);
    printf("\n\n");
}

int height(node *root)
{
    if(!root)
        return 0;
    
    int x,y;
    x = height(root->left);
    y = height(root->right);

    return x>y?x+1:y+1;
}

node* in_pre(node *root)
{
    if(!root->left)
        return 0;

    root = root->left;
    node *p = root;
    while(root)
    {
        p = root;
        root = root->right;
    }
    return p;
}

node* in_suc(node *root)
{
    if(!root->right)
        return 0;

    root = root->right;
    node *p = root;
    while(root)
    {
        p = root;
        root = root->left;
    }
    return p;
}

node* insert(node *root, int data)
{
    if(!root)
    {
        root = (node *)malloc(sizeof(node));
        root->key = data;
        root->left = root->right = NULL;
        return root;
    }
    if(root->key == data)
    {
        printf("Element already present!\n");
        return root;
    }
    if(root->key > data)
        root->left = insert(root->left, data);

    else if(root->key < data)
        root->right = insert(root->right, data);

    return root;
    
}

void create(node **root)
{
    int x = 0;
    while(x != -1)
    {
        printf("Enter data (-1 for no node) : ");
        scanf("%d",&x);
        if(x != -1)
            *root = insert(*root, x);
    }
}

node* delete(node *root, int data)
{
    if(!root)
    {
        printf("Element not found!\n");
        return NULL;
    }

    if(root->key == data && !root->left && !root->right)
    {
        free(root);
        root = NULL;
        return root;
    }
    else if(root->key == data)
    {
        if(height(root->left) > height(root->right))
        {
            node *q = in_pre(root);
            root->key = q->key;
            root->left = delete(root->left, q->key);
        }
        else
        {
            node *q = in_suc(root);
            root->key = q->key;
            root->right = delete(root->right, q->key);
        }
    }
    else if(root->key > data)
        root->left = delete(root->left, data);
    else if(root->key < data)
        root->right = delete(root->right, data);

    return root;
    
}

void preorder(node *root)
{
    if(!root)
        return;

    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if(!root)
        return;

    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

void postorder(node *root)
{
    if(!root)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}