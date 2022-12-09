#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int key;
    struct node *right;
} node;

typedef struct queue
{
    node *data;
    struct queue *next;
} queue;

void enqueue(queue **front, queue **rear, node *data)
{
    queue *temp = (queue *)malloc(sizeof(queue));
    if(!temp)
    {
        printf("Overflow!");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if(!*front)
        *front = *rear = temp;

    else
    {
        (*rear)->next = temp;
        *rear = temp;
    }
}

node* dequeue(queue **front, queue **rear)
{
    if(!*front)
    {
        printf("Underflow!\n");
        return 0;
    }

    node *x = (*front)->data;
    queue *temp = *front;
    *front = (*front)->next;
    free(temp);
    return x;
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

void levelorder(node *root)
{
    queue *front =0, *rear = 0;
    if(!root)
        return;

    node *ptr = 0;

    enqueue(&front,&rear, root);
    do
    {
        ptr = dequeue(&front, &rear);
        printf("%d ",ptr->key);
        if(ptr->left)
            enqueue(&front,&rear, ptr->left);
        if(ptr->right)
            enqueue(&front,&rear, ptr->right);
    } while(front);
}

int count(node *root)
{
    int x,y;
    if(root)
    {
        x = count(root->left);
        y = count(root->right);
        return x+y+1;
    }
    return 0;
}

void main()
{
    node *root = 0;
    root = create();
    levelorder(root);
    printf("\nHello");
    printf("\nNodes = %d\n",count(root));
}