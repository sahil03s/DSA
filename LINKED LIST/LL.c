#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
}*start = NULL;
typedef struct node node;

void reverse(node *p,node *q)
{
    if(p == NULL)
    {
        start = q;
    }
    else
    {
        reverse(p->next,p);
        p->next = q;
    }
}
void display()
{
    if(start == NULL)
    {
        printf("No elements present!\n");
        return;
    }
    struct node *temp = start;
    for(;temp != NULL; temp = temp->next)
    printf("%d ",temp->info);
    printf("\n");
}

void insert_beg(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->next = start;
    start = temp;
}

void insert_end(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    if(start == NULL)
    {
        insert_beg(item);
        return;
    }
    temp->next = NULL;
    struct node *q = start;
    for(; q->next != NULL; q = q->next);
    q->next = temp;
}
void sorting()
{
    int temp;
    for(node *p = start; p->next!= NULL; p = p->next)
    for(node *q = p->next; q != NULL; q=q->next)
    if(p->info > q->info)
    {
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
}
void main()
{
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(2);
    insert_end(1);
    insert_end(10);
    display();
    reverse(start,NULL);
    display();
    sorting();
    display();
}