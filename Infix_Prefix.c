/* C program to convert infix expression to postfix expression
   Name of the program: Infix_Prefix.c
*/

#include <stdio.h>
#include <string.h>

char stk[100], infix[100], prefix[100];
int tos = -1;

int precedence(char c)
{
    switch (c)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(':
        case ')':
        return 0;
    }
}

void push(char c)
{
    if (tos == 99)
    {
        printf("Stack OVerflow");
        return;
    }
    stk[++tos] = c;
}

char pop()
{
    if (tos == -1)
        printf("Stack underflow");
    else
        return stk[tos--];
}

void inToPre()
{
    int i, j = 0;
    char next, c;
    for (i = strlen(infix) - 1; i > -1; i--)
    {
        c = infix[i];
        if (c != ' ')
        {
            switch (c)
            {
                case ')': push(c); break;
                case '(': while ((next = pop()) != ')')
                            prefix[j++] = next;
                          break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^': while (tos != -1 && precedence(stk[tos]) > precedence(c))
                            prefix[j++] = pop();
                          push(c);
                          break;
                default: prefix[j++] = c;
            }
        }
    }

    while (tos != -1)
    {
        prefix[j++] = pop();
        prefix[j] = '\0';
    }
    for (i = strlen(prefix) - 1; i > -1; i--)
        printf("%c", prefix[i]);
}

void main()
{
    int c;
    printf("Enter infix expression: ");
    gets(infix);
    printf("The prefix expression: ");
    inToPre();
}