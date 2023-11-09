#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
}*start = NULL;

void display();
void insert_beg(int item);
void insert_end(int item);
void insert_pos(int item, int pos);
void insert_sp_el(int item, int element);
void del_beg();
void del_end();
void del_pos(int pos);
void del_sp_el(int element);
void reverse();

void main()
{
    printf("Hello User!\n");
    int item,opt=0,op;
    int pos,element;
    while(opt!=5)
    {
        printf("\n1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");
        printf("\nChoose an option : ");
        scanf("%d",&opt);
        while(opt < 1 || opt > 5)
        {
            printf("Choose valid option : ");
            scanf("%d",&opt);
        }
        switch(opt)
        {
            case 1:
                    display();
                    break;
            case 2:
                    printf("1. Insert at beginning\n");
                    printf("2. Insert at end\n");
                    printf("3. Insert at specific position\n");
                    printf("4. Insert after specific element\n");
                    printf("\nChoose an option : ");
                    scanf("%d",&op);
                    while(op < 1 || op > 4)
                    {
                        printf("Choose valid option : ");
                        scanf("%d",&op);
                    }
                    switch(op)
                    {
                        case 1:
                                printf("Enter the element to be added : ");
                                scanf("%d",&item);
                                insert_beg(item);
                                break;
                        case 2:
                                printf("Enter the element to be added : ");
                                scanf("%d",&item);
                                insert_end(item);
                                break;
                        case 3:
                                printf("Enter the position at which element is to be added : ");
                                scanf("%d",&pos);
                                printf("Enter the element to be added : ");
                                scanf("%d",&item);
                                insert_pos(item,pos);
                                break;
                        case 4:
                                printf("Enter the element after which element is to be added : ");
                                scanf("%d",&element);
                                printf("Enter the element to be added : ");
                                scanf("%d",&item);
                                insert_sp_el(item,element);
                                break;
                    }
                    break;
            case 3:
                    printf("1. Delete from beginning\n");
                    printf("2. Delete from end\n");
                    printf("3. Delete specific position\n");
                    printf("4. Delete specific element\n");
                    printf("\nChoose an option : ");
                    scanf("%d",&op);
                    while(op < 1 || op > 4)
                    {
                        printf("Choose valid option : ");
                        scanf("%d",&op);
                    }
                    switch(op)
                    {
                        case 1:
                                del_beg();
                                break;
                        case 2:
                                del_end();
                                break;
                        case 3:
                                printf("Enter position to be deleted : ");
                                scanf("%d",&pos);
                                del_pos(pos);
                                break;
                        case 4:
                                printf("Enter element to be deleted : ");
                                scanf("%d",&element);
                                del_sp_el(element);
                                break;
                    }
                    break;
            case 4:
                    reverse();
                    break;
            case 5:
                    printf("\n\nThank you!\n");
                    break;
        }
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

void insert_pos(int item, int pos)
{
    if(pos == 1)
    {
        insert_beg(item);
        return;
    }
    else if(start == NULL)
    {
        printf("Position not found!\n");
        return;
    }
    struct node *q = start;
    for(int i=1; i < pos-1; i++, q = q->next)
    {
        if(q->next == NULL)
        {
            printf("Position not found!\n");
            return;
        }
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->info = item;
    temp->next = q->next;
    q->next = temp;
}

void insert_sp_el(int item, int element)
{
    if(start == NULL)
    {
        printf("Element not found!\n");
        return;
    }
    struct node *q = start;
    for(; q->info != element; q = q->next)
    {
        if(q->next == NULL)
        {
            printf("Element not found!\n");
            return;
        }
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->next = q->next;
    q->next = temp;
}

void del_beg()
{
    if(start == NULL)
    {
        printf("No elements found for deletion!\n");
        return;
    }
    struct node *q = start;
    start = start->next;
    free(q);
}

void del_end()
{
    if(start == NULL)
    {
        printf("No elements found for deletion!\n");
        return;
    }
    if(start->next == NULL)
    {
        del_beg();
        return;

    }
    struct node *q = start, *prev = NULL;
    for(; q->next != NULL; q = q->next)
    {
        prev=q;
    }
    free(q);
    prev->next = NULL;
}

void del_pos(int pos)
{
    if(start == NULL)
    {
        printf("No elements found for deletion!\n");
        return;
    }
    if(pos == 1)
    {
        del_beg();
        return;
    }
    struct node *q = start, *prev = NULL;
    for(int i=1; i < pos; i++, q = q->next)
    {
        prev = q;
        if(q->next == NULL)
        {
            printf("Position not found!\n");
            return;
        }
    }
    prev->next = q->next;
    free(q);
}

void del_sp_el(int element)
{
    if(start == NULL)
    {
        printf("No elements found for deletion!\n");
        return;
    }
    if(start->info == element)
    {
        del_beg();
        return;
    }
    struct node *q = start, *prev = NULL;
    for( ; q->info != element; q = q->next)
    {
        prev = q;
        if(q->next == NULL)0
        {
            printf("Element to be deleted not present!\n");
            return;
        }
    }
    prev->next = q->next;
    free(q);
}

void reverse()
{
    if(start == NULL)
    {
        printf("No elements found for reversing!\n");
        return;
    }
    struct node *prevnode = NULL, *q = start , *nextnode = start;
    while(q != NULL)
    {
        nextnode = nextnode->next;
        q->next = prevnode;
        prevnode = q;
        q = nextnode;
    }
    start = prevnode;
}
