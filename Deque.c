/* C program to implement deque(double ended queue) with static and dynamic memory allocation mechanism using  array storage representation
   Name of the program:Deque.c
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

struct DequeS
{
    int front;
    int rear;
    int QS[N];
} q;

struct DequeD
{
    int size;
    int front;
    int rear;
    int *QD;
};

void StaticDeque();
void enqueuefrontS();
void enqueuerearS();
void dequeuefrontS();
void dequeuerearS();
int isEmptyS();
int isFullS();
void peekfrontS();
void peekrearS();
void displayS();

void DynamicDeque();
void  create_D();
void enqueuefrontD();
void enqueuerearD();
void dequeuefrontD();
void dequeuerearD();
int isEmptyD();
int isFullD();
void peekfrontD();
void peekrearD();
void displayD();

void main()
{
    int choice;
    printf("\n**MAIN MENU**\nEnter\n1->To perform deque operations using static memory mechanism\n2->To perform circular queue operations using dynamic array mechanism\n-1->To exit!\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:StaticDeque();break;
        case 2:DynamicDeque();break;
        case -1:exit(0);
        default:printf("Invalid choice\n"); break;
    }
}

void menu()
{
    printf("\n\n***DEQUE OPERATIONS***\nEnter\n1->To enqueue the element to the front of deque\n2->To enqueue the element to the rear end of deque\n3->To enqueue the front elemnt of the deque\n4->To enqueue the rear elemnt of the deque\n5->To print the front element of the deque\n6->To print the rear element of the deque\n7->To display the elememt(s) of the deque\n0->Go to main menu\n-1->To exit!\n");
}

void StaticCQueue()
{
    q.front = q.rear = -1;
    int choice;
    menu();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:enqueuefrontS(); break;
            case 2:enqueuerearS(); break;
            case 3:dequeuefrontS();break;
            case 4:dequeuerearS();break;
            case 5:peekfrontS();break;
            case 6:peekrearS(); break;
            case 7:displayS(); break;
            case 0:main(); break;
            case -1:exit(0);
            default:printf("\nInvalid choice!\n");break;
        }
    } while (choice != -1);
}

void enqueuefrontS()
{
    if (isFullS())
    {
        printf("The deque is full\n");
        return;
    }
    int x;
    printf("Enter the data to be enqueued: "); scanf("%d", &x);
    if (isEmptyS())
    {
        q.rear++;
        q.QS[++q.front] = x;
    }
    else if(q.front == 0 && q.rear == 0)
    {
        q.front = N - 1;
        q.QS[q.front] = x;
    }
    else
    {
        q.QS[--q.front] = x;
    }
    printf("%d is enqueued into the deque successfully\n", x);
}

void enqueuerearS()
{
    if (isEmptyS())
    {
        printf("The deque is full\n");
        return;
    }
    int x;
    printf("Enter the data to be enqueued: "); scanf("%d", &x);
    if (isEmptyS())
    {
        q.front++;
        q.QS[++q.rear] = x;
    }
    else if(q.rear == N - 1)
    {
        q.rear = 0;
        q.QS[q.rear] = x;
    }
    else
    {
        q.QS[++q.rear] = x;
    }
    printf("%d is enqueued into the deque successfully\n", x);
}

void dequeuefrontS()
{
    if (isEmptyS())
    {
        printf("The deque is empty\n");
        return;
    }
    int x;
    if (q.front == q.rear)
    {
        x = q.QS[q.front];
        q.front = q.rear = -1;
    }
    else if(q.front == N -1)
    {
        x = q.QS[q.front];
        q.front = 0;
    }
    else
        x = q.QS[q.front++];
    printf("%d has been dequeued from the deque\n", x);
}

void dequeuerearS()
{
    if (isEmptyS())
    {
        printf("The deque is empty\n");
        return;
    }
    int x;
    if (q.front == q.rear)
    {
        x = q.QS[q.front];
        q.front = q.rear = -1;
    }
    else if(q.rear == 0)
    {
        x = q.QS[q.rear];
        q.rear = N - 1;
    }
    else
    {
        x = q.QS[q.rear--];
    }
    printf("%d has been dequeued from the deque\n", x);
}

void peekfrontS()
{
    if (isEmptyS())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("The element at the front end of the deque is %d\n", q.QS[q.front]);
}

void peekrearS()
{
    if (isEmptyS())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("The element at the front end of the deque is %d\n", q.QS[q.rear]);
}

void displayS()
{
    if (isEmptyS())
    {
        printf("The deque is empty\n");
        return;
    }
    int i;
    printf("\nThe elemets of deque is/are: ");
    while(i != q.rear)
    {
         printf("%d  ", q.QS[i]);
         i = (i + 1) % N;
    }
    printf("%d\n",q.QS[q.rear]);
}

int isFullS()
{
    if ((q.front == 0 && q.rear == N - 1) || (q.front == q.rear + 1))
        return 1;
    else
        return 0;
}

int isEmptyS()
{
    if(q.rear == -1 && q.front == -1)
        return 1;
    else
        return 0;
}

void DynamicDeque()
{
    int n, x, choice;
    printf("Enter the size of the deque: ");
    scanf("%d", &n);
    struct DequeD q;
    create_D(&q, n);
    menu();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:enqueuefrontD(&q); break;
            case 2:enqueuerearD(&q); break;
            case 3:dequeuefrontD(&q);break;
            case 4:dequeuerearD(&q);break;
            case 5:peekfrontD(q);break;
            case 6:peekrearD(q); break;
            case 7:displayD(q); break;
            case 0:main(); break;
            case -1:exit(0);
            default:printf("\nInvalid choice!\n");break;
        }
    } while (choice != -1);
}

void create_D(struct DequeD *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->QD = (int *)malloc(size * sizeof(int));
}

void enqueuefrontD(struct DequeD *q)
{
    if ((q->front == 0 && q->rear == N - 1) || (q->front == q->rear + 1))
    {
        printf("The deque is full\n");
        return;
    }
    int x;
    printf("Enter the data to be enqueued: "); scanf("%d", &x);
    if (q->rear == -1 && q->front == -1)
    {
        q->rear++;
        q->QD[++q->front] = x;
    }
    else if(q->front == 0 && q->rear == 0)
    {
        q->front = N - 1;
        q->QD[q->front] = x;
    }
    else
    {
        q->QD[--q->front] = x;
    }
    printf("%d is enqueued into the deque successfully\n", x);
}

void enqueuerearD(struct DequeD *q)
{
    if ((q->front == 0 && q->rear == N - 1) || (q->front == q->rear + 1))
    {
        printf("The deque is full\n");
        return;
    }
    int x;
    printf("Enter the data to be enqueued: "); scanf("%d", &x);
    if (q->rear == -1 && q->front == -1)
    {
        q->front++;
        q->QD[++q->rear] = x;
    }
    else if(q->rear == N - 1)
    {
        q->rear = 0;
        q->QD[q->rear] = x;
    }
    else
    {
        q->QD[++q->rear] = x;
    }
    printf("%d is enqueued into the deque successfully\n", x);
}

void dequeuefrontD(struct DequeD *q)
{
    if (q->rear == -1 && q->front == -1)
    {
        printf("The deque is empty\n");
        return;
    }
    int x;
    if (q->front == q->rear)
    {
        x = q->QD[q->front];
        q->front = q->rear = -1;
    }
    else if(q->front == N -1)
    {
        x = q->QD[q->front];
        q->front = 0;
    }
    else
        x = q->QD[q->front++];
    printf("%d has been dequeued from the deque\n", x);
}

void dequeuerearD(struct DequeD *q)
{
    if (q->rear == -1 && q->front == -1)
    {
        printf("The deque is empty\n");
        return;
    }
    int x;
    if (q->front == q->rear)
    {
        x = q->QD[q->front];
        q->front = q->rear = -1;
    }
    else if(q->rear == 0)
    {
        x = q->QD[q->rear];
        q->rear = N - 1;
    }
    else
        x = q->QD[q->rear--];
    printf("%d has been dequeued from the deque\n", x);
}

void peekfrontD(struct DequeD q)
{
    if (isEmptyD())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("The element at the front end of the deque is %d\n", q.QD[q.front]);
}


void peekrearD(struct DequeD q)
{
    if (isEmptyD())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("The element at the front end of the deque is %d\n", q.QD[q.rear]);
}

void displayD(struct DequeD q)
{
    if (isEmptyD())
    {
        printf("The deque is empty\n");
        return;
    }
    int i = q.front;
    printf("\nThe elemets of deque is/are: ");
    while(i != q.rear)
    {
         printf("%d  ", q.QD[i]);
         i = (i + 1) % N;
    }
    printf("%d\n",q.QD[q.rear]);
}

int isFullD(struct DequeD q)
{
    if ((q.front == 0 && q.rear == N - 1) || (q.front == q.rear + 1))
        return 1;
    else
        return 0;
}

int isEmpty_D(struct DequeD q)
{
    if (q.front == -1 && q.rear == -1)
        return 1;
    else
        return 0;
}

