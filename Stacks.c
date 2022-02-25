/*  C program to implement Stack with static and dynamic memory allocation mechanisms using array storage representation
    Name of the program : Stacks.c
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

struct Stack_S
{
    int top;
    int stack_S[N];
}s;

struct Stack
{
    int size;
    int top;
    int *S;
};

void Static_Stack();
void push_S();
void pop_S();
int isEmpty_S();
int isFull_S();
void peek_S();
void display_S();

void Dynamic_Stack(); 
void create_D(struct Stack *);
void push_D();
void pop_D(); 
int isEmpty_D();
int isFull_D();
void peek_D(); 
void display_D();

void main()
{
    int choice;
    printf("\n**MAIN MENU**\nEnter\n1->To perform stack operations using static memory allocation\n2->To perform stack operations using dynamic memory allocation\n-1->To exit!\n");
    printf("Enter your choice: ");  
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: Static_Stack(); break;
        case 2: Dynamic_Stack(); break;
        case -1: exit(0);
        default : printf("Invalid choice\n"); 
    }
}

void menu()
{
    printf("\n***STACK OPERATIONS***\nEnter\n1->To push the element into the stack\n2->To pop the element from the stack\n3->To print the top-most element of the stack\n4->To display the elememt(s) of the stack\n0->Go to main menu\n-1->To exit!\n");
}

void Static_Stack()
{
    int choice;
    s.top = -1;
    menu();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: push_S(); break;
            case 2: pop_S(); break;
            case 3: peek_S(); break;
            case 4: display_S(); break;
            case 0: main(); break;
            case -1: exit(0);
            default : printf("\nInvalid choice!\n"); 
        }
    }while(choice != -1);
}

void push_S()
{
    if(isFull_S())
    {
        printf("STACK OVERFLOW.......\n");
        return;
    }
    int x;
    printf("Enter data to be pushed: ");
    scanf("%d",&x);
    s.stack_S[++s.top] = x;
    printf("%d is pushed into the stack successfully\n",x);
}

void pop_S()
{
    if(isEmpty_S())
    {
        printf("STACK UNDERFLOW......\n");
        return;
    }
    int item = s.stack_S[s.top];
    s.top--;
    printf("%d has been popped from the stack\n",item);
}

void peek_S()
{
    if(isEmpty_S())
    {
        printf("STACK UNDERFLOW......\n");
        return;
    }
    printf("The top-most element of the stack is %d\n",s.stack_S[s.top]);
}

int isFull_S()
{
    if(s.top == (N-1))
        return 1;
    else
        return 0;
}

int isEmpty_S()
{
    if(s.top == -1)
        return 1;
    else
        return 0;
}

void display_S()
{
    int i;
    if(isEmpty_S())
    {
        printf("STACK UNDERFLOW\n");
        return;
    }
    printf("The elemet(s) of stack is/are: ");
    for(i = s.top; i > -1; i--)
        printf("%d  ",s.stack_S[i]);
    printf("\n");
}


void Dynamic_Stack()
{
    struct Stack st;
    create_D(&st);
    menu();
    int choice;
    do
    {
        printf("\nEnter your choice: "); 
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: push_D(&st); break;
            case 2: pop_D(&st); break;
            case 3: peek_D(st); break;
            case 4: display_D(st); break;
            case 0: main(); break;
            case -1: exit(0);
            default : printf("\nInvalid choice!\n");
        }
    }while(choice != -1);
}



void create_D(struct Stack *st)
{
    int x;
    printf("Enter MAX size of the Stack: ");
    scanf("%d", &x);
    st->size = x;
    st->top = -1;
    st->S = (int *)malloc(x*sizeof(int));
}

void display_D(struct Stack st)
{
    if (isEmpty_D(st))
        printf("STACK UNDERFLOW\n");
    else
    {
        printf("The element(s) of stack is/are: ");
        for (int i = st.top; i >= 0; i--)
            printf("%d ", st.S[i]);
        printf("\n");
    }
}

void push_D(struct Stack *st)
{
    int n;
    if (st->top == (st->size - 1))
        printf("STACK OVERFLOW\n");
    else
    {
        printf("Enter the data to be pushed into the stack: "); 
        scanf("%d", &n); 
        st->top++;
        st->S[st->top] = n;
        printf("%d has been pushed into the stack successfully\n",n);
    }
}

void pop_D(struct Stack *st)
{
    if (st->top == -1)
    {
        printf("STACK UNDERFLOW\n");
        return;
    }
    int x = st->S[st->top--];
    printf("%d is popped from the stack\n",x);
}

int isEmpty_D(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int isFull_D(struct Stack st)
{
    if (st.top == (st.size-1))
        return 1;
    else
    return 0;
}

void peek_D(struct Stack st)
{
    if (!isEmpty_D(st))
        printf("The top-most element of the stack is %d\n", st.S[st.top]);
    else
        printf("STACK UNDERFLOW!\n");
}