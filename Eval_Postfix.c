/* C program to evaluate postfix expression
   Name of the program: Eval_Postfix.c
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

char postfix[100];
int stack[100];
int top = -1;

void push2(int n)
{
    if (top == 99)
        printf("stack overflow");
    else
        stack[++top] = n;
}
int pop2()
{
    if (top == -1)
        printf("Underflow");
    else
        return stack[top--];
}

int post_eval()
{
    int i, a, b;
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            push2(postfix[i] - '0');
        else
        {
            a = pop2();
            b = pop2();
            switch (postfix[i])
            {
                case '+': push2(b + a); break;
                case '-': push2(b - a); break;
                case '*': push2(b * a); break;
                case '/': push2(b / a); break;
                case '^': push2(pow(b, a)); break;
            }
        }
        printf("%d  %d\n",stack[top],i);
    }
    return pop2();
}

void main()
{
    int c;
    printf("Enter postfix expression: ");
    gets(postfix);
    printf("Result: %d", post_eval());
}
