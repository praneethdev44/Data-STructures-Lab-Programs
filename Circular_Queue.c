#include <stdio.h>
#include <stdlib.h>
#define N 5

struct CQueue_S
{
    int front;
    int rear;
    int Cqueue_S[N];
} q;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Static_CQueue();
void enqueue_S();
void dequeue_S();
int isEmpty_S();
int isFull_S();
void peek_S();
void display_S();

void Dynamic_CQueue();
void create_D(struct Queue*,int);
void enqueue_D(struct Queue*);
void dequeue_D(struct Queue*);
int isEmpty_D(struct Queue);
int isFull_D(struct Queue);
void peek_D(struct Queue);
void display_D(struct Queue);

void main()
{
    int choice;
    printf("\n**MAIN MENU**\nEnter\n1->To perform circular queue operations using static memory mechanism\n2->To perform circular queue operations using dynamic array mechanism\n-1->To exit!\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: Static_CQueue(); break;
        case 2: Dynamic_CQueue(); break;
        case -1: exit(0);
        default: printf("Invalid choice\n"); break;
    }
}

void menu()
{
    printf("\n***QUEUE OPERATIONS***\nEnter\n1->To enqueue the element into the queue\n2->To dequeue the element from the stack\n3->To print the front element of the queue\n4->To display the elememt(s) of the queue\n0->Go to main menu\n-1->To exit!\n");
}

void Static_CQueue()
{
    q.front = q.rear = -1;
    menu();
    int choice;
    do
    {
        printf("\nEnter your choice: "); scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue_S(); break;
            case 2: dequeue_S(); break;
            case 3: peek_S(); break;
            case 4: display_S(); break;
            case 0: main(); break; 
            case -1: exit(0);
            default: printf("\nInvalid choice!\n"); break;
        }
    } while (choice != -1);
}

void enqueue_S()
{
    if (isFull_S())
    {
        printf("QUEUE OVERFLOW.......\n");
        return;
    }
    int x;
    printf("Enter the data to be enqueued: ");
    scanf("%d", &x);
    if (isEmpty_S())
        q.Cqueue_S[++q.front] = q.Cqueue_S[++q.rear] = x;
    else
    {
        q.rear = (q.rear + 1) % N;
        q.Cqueue_S[q.rear] = x;
    }
    printf("%d is enqueued into the queue successfully\n", x);
}

void dequeue_S()
{
    if (isEmpty_S())
    {
        printf("QUEUE UNDERFLOW......\n");
        return;
    }
    int x;
    if (q.front == q.rear)
    {
        x = q.Cqueue_S[q.front];
        q.front = q.rear = -1;
    }
    else
    {
        x = q.Cqueue_S[q.front];
        q.front = (q.front + 1) % N;
    }
    printf("%d has been dequeued from the queue\n", x);
}

void peek_S()
{
    if (isEmpty_S())
    {
        printf("QUEUE UNDERFLOW......\n");
        return;
    }
    printf("The front element of the queue is %d\n", q.Cqueue_S[q.front]);
}

int isFull_S()
{
    if ((q.rear + 1) % N == q.front)
        return 1;
    else
        return 0;
}

int isEmpty_S()
{
    if (q.rear == -1 && q.front == -1)
        return 1;
    else
        return 0;
}

void display_S()
{
    printf("The elemet(s) of queue is/are: ");
    for (int i = q.front; i <= q.rear; i++)
        printf("%d  ", q.Cqueue_S[i]);
    printf("\n");
}

void Dynamic_CQueue()
{
    int n, choice;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    struct Queue q;
    create_D(&q, n);
    menu();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue_D(&q); break;
            case 2: dequeue_D(&q); break;
            case 3: peek_D(q); break;
            case 4: display_D(q); break;
            case 0: main(); break;
            case -1: exit(0);
            default: printf("\nInvalid choice!\n"); break;
        }
    } while (choice != -1);
}

void create_D(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(size * sizeof(int));
}

void enqueue_D(struct Queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full\n");
        return;
    }
    int x;
    printf("Enter the data to be enqueued: ");
    scanf("%d", &x);
    if(q->rear == -1 && q->rear == -1)
        q->front++;
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
    printf("%d has been enqueued into the queue\n",x);
}

void dequeue_D(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    int x = q->Q[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->size;
    printf("%d has been dequeued from the queue\n",x);
}

void display_D(struct Queue q)
{
    int i = q.front;
    if (isEmpty_D(q))
        printf("Queue is Empty\n");
    else
    {
        printf("The element(s) of the queue are: ");
        do
        {
            printf("%d ", q.Q[i]);
            i = (i + 1) % q.size;
        } while (i != (q.rear + 1) % q.size);
        printf("\n");
    }
}

int isEmpty_D(struct Queue q)
{
    if (q.front == q.rear)
        return 1;
    else
        return 0;
}

int isFull_D(struct Queue q)
{
    if ((q.rear + 1) % q.size == q.front)
        return 1;
    else
        return 0;
}

void peek_D(struct Queue q)
{
    if (isEmpty_D(q))
        printf("Queue is Empty\n");
    else
        printf("The front element of the queue is %d\n", q.Q[q.front]);
}
