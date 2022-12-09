#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int key;
    struct node *right;
} node;

int height(node *root)
{
    if(!root)
        return 0;
    
    int x,y;
    x = height(root->left);
    y = height(root->right);
    
    return x>y?x+1:y+1;
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