#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
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

void push(node **top, int info)
{
    node *temp = (node *)malloc(sizeof(node));
    if(!temp)
        return;

    temp->data = info;
    temp->next = *top;
    *top = temp;
}

int pop(node **top)
{
    if(!*top)
    {
        printf("Underflow!");
        return INT_MIN;
    }
    int x = (*top)->data;
    node *temp = *top;
    *top = (*top)->next;
    free(temp);
    return x;
}

int peek(node *top)
{
    if(!top)
    {
        printf("Underflow!");
        return INT_MIN;
    }

    return top->data;
}

void display(node *top)
{
    if(top == NULL)
        printf("Underflow!");
    else
        while(top)
        {
            printf("%d ",top->data);
            top = top->next;
        }
}

int isOperand(char ch)
{
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}
int inPre(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 3;
        case '^':
                return 6;
        case ')':
                return 0;
    }
    return INT_MIN;
}

int outPre(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
                return 2;
        case '*':
        case '/':
        case '%':
                return 4;
        case '^':
                return 5;
        case '(':
                return 100;
    }
    return INT_MAX;
}
char* reverse(char *s)
{
    node *top = NULL;

    int i = 0;
    while(s[i])
    {
        push(&top, s[i++]);
    }
    i = -1;
    while(!isEmpty(top))
    {
        s[++i] = pop(&top);
    }
    s[++i] = '\0';
    return s;
}

char* inToPre(char *s)
{
    s = reverse(s);
    node *top = NULL;
    char *pre = (char *)malloc((strlen(s)+1) * sizeof(char));
    if(!pre)
        return NULL;

    int i = 0, k = -1;
    while(s[i])
    {
        if(isOperand(s[i]))
        pre[++k] = s[i];
        else if(s[i] == ')')
            push(&top, s[i]);
        else if(s[i] == '(')
        {
            while(!isEmpty(top) && peek(top) != ')')
                pre[++k] = pop(&top);
            if(!isEmpty(top) && peek(top) != ')')
                return NULL; //Invalid Expression
            else
            pop(&top);
        }
        else
        {
            while(!isEmpty(top) && inPre(peek(top)) > outPre(s[i]))
                pre[++k] = pop(&top);
            push(&top, s[i]);
        }
        i++;
    }
    while(!isEmpty(top))
        pre[++k] = pop(&top);
    pre[++k] = '\0';
    pre = reverse(pre);
    return pre;
}

int eval_pre(char *pre)
{
    pre = reverse(pre);
    node *top = NULL;
    int i = 0, num1, num2;
    while(pre[i])
    {
        if(isOperand(pre[i]))
            push(&top, pre[i] - '0');
        else
        {
            num2 = pop(&top);
            num1 = pop(&top);
            switch(pre[i])
            {
                case '+':
                    push(&top, num2 + num1);
                    break;
                case '-':
                    push(&top, num2 - num1);
                    break;
                case '*':
                    push(&top, num2 * num1);
                    break;
                case '/':
                    push(&top, num2 / num1);
                    break;
                case '%':
                    push(&top, num2 % num1);
                    break;
                case '^':
                    push(&top, pow(num2,num1));
                    break;
            }
        }
        i++;
    }
    return pop(&top);
}



void main()
{  
    char infix[50], *prefix = NULL;
    printf("Input infix expression :\n");
    scanf("%s",infix);
    prefix = inToPre(infix);
    printf("\nInfix expression :\n%s",infix);
    printf("\n\nPrefix expression :\n%s",prefix);
    int x = eval_pre(prefix);
    printf("\nEvaluated value = %d\n",x);
}
