#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct Stack
{
    int top;
    unsigned size;
    int *array;
};
typedef struct Stack Stack;

Stack* createstack(unsigned capacity)
{
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    if(!stack)
        return NULL;

    stack->top = -1;
    stack->size = capacity;
    stack->array = (int *)malloc(stack->size * sizeof(int));
    
    if(!stack->array)
        return NULL;
    
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}
int peek(Stack *stack)
{
    if(stack->top == -1)
    {
        printf("Underflow!");
        return INT_MIN;
    }
    else    
        return stack->array[stack->top];
}

int pop(Stack *stack)
{
    if(stack->top == -1)
    {
        printf("Underflow!");
        return INT_MIN;
    }
    else
        return stack->array[stack->top--];
}

void push(Stack *stack, int x)
{
    if(stack->top == stack->size - 1)
    {
        printf("Overflow!");
        return;
    }
    else
    {
        stack->array[++stack->top] = x;
    }
}

int isOperand(char ch)
{
    if(ch >=65 && ch <=90 || ch >=97 && ch <= 122 || ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int inPrec(char ch)
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
            return 0;
    }
    return 0;
}

int outPrec(char ch)
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
        case '(':
            return 100;
    }
    return 0;
}

char* inToPost(char *s)
{
    Stack *stack = createstack(strlen(s));
    char *post = (char *)malloc(strlen(s)*sizeof(char));
    if(!stack)
        return NULL;
    int i = 0, k = -1;
    while(s[i] != '\0')
    {
        if(isOperand(s[i]))
        {
            post[++k] = s[i];
        }
        else if(s[i] == '(')
            push(stack,s[i]);
        else if(s[i] == ')')
        {
            while(!isEmpty(stack) && peek(stack) != '(')
            {
                post[++k] = pop(stack);
            }
            if(!isEmpty(stack) && peek(stack) != '(')
                return NULL;
            else
                pop(stack);
        }
        else
        {
            while(!isEmpty(stack) && inPrec(peek(stack)) > outPrec(s[i]))
                post[++k] = pop(stack);
            push(stack,s[i]);
        }
        i++;
    }

    while(!isEmpty(stack))
    {
        post[++k] = pop(stack);
    }
    post[++k] = '\0';
    return post;
}

int eval_post(char *post)
{
    Stack *stack = createstack(strlen(post));
    if(!stack)
        return INT_MIN;
    int i;
    for(i = 0; post[i]; i++)
    {
        if(isdigit(post[i]))
            push(stack, post[i] - '0');
        else
        {
            int num1 = pop(stack);
            int num2 = pop(stack);
            switch(post[i])
            {
                case '+':
                    push(stack, num2 + num1);
                    break;
                case '-':
                    push(stack, num2 - num1);
                    break;
                case '*':
                    push(stack, num2 * num1);
                    break;
                case '/':
                    push(stack, num2 / num1);
                    break;
                case '%':
                    push(stack, num2 % num1);
                    break;
                case '^':
                    push(stack,pow(num2,num1));
                    break;
            }
        }
    }
    return pop(stack);
}
void main()
{
    char infix[50];
    printf("Input the string :\n");
    scanf("%s",infix);
    char *postfix = inToPost(infix);
    int i = 0;
    while(postfix[i])
        printf("%c",postfix[i++]);
    int x = eval_post(postfix);
    printf("\n%d\n",x);
}