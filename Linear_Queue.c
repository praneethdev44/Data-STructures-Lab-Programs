/* C program to implement ordinary queue with static and dynamic memory allocation mechanisms using array storage representation.
   Name of the program:LinearQueue.c
*/

#include<stdio.h>
#include<stdlib.h>
#define N 5

struct Queue_S
{
    int front;
    int rear;
    int queue_S[N];
}q;

struct Queue_D
{
 int size;
 int front;
 int rear;
 int *queue_D;
};

void Static_Queue();
void enqueue_S();
void dequeue_S();
int isEmpty_S();
int isFull_S();
void peek_S();
void display_S();

void Dynamic_Queue();
void create_D(struct Queue_D*,int); 
void enqueue_D(struct Queue_D*);
void dequeue_D(struct Queue_D*);
int isEmpty_D(struct Queue_D);
void peek_D(struct Queue_D);
void display_D(struct Queue_D);

void main()
{
    int choice;
    printf("\n**MAIN MENU**\nEnter\n1->To perform queue operations using static memory allocation mechanism\n2->To perform queue operations using dynamic memory allocation mechanism\n-1->To exit!\n");
    printf("Enter your choice: ");  scanf("%d", &choice);
    switch(choice)
    {
        case 1: Static_Queue(); break;
        case 2: Dynamic_Queue(); break;
        case -1: exit(0);
        default : printf("Invalid choice\n"); break;
    }
}

void menu()
{
    printf("\n***QUEUE OPERATIONS***\nEnter\n1->To enqueue the element into the queue\n2->To dequeue the element from the stack\n3->To print the front element of the queue\n4->To display the elememt(s) of the queue\n0->Go to main menu\n-1->To exit!\n\n");
}

void Static_Queue()
{
    q.front = q.rear = -1;
    int choice;
    menu();
    do
    {
        printf("\nEnter your choice: "); scanf("%d",&choice);
        switch (choice)
        {
            case 1: enqueue_S(); break;
            case 2: dequeue_S(); break;
            case 3: peek_S(); break;
            case 4: display_S(); break;
            case 0: main(); break;
            case -1: exit(0);
            default : printf("\nInvalid choice!\n");  break;
        }
    }while(choice != -1);
}


void enqueue_S()
{
    if(isFull_S())
    {
        printf("Queue is full\n");
        return;
    }
    int x;
    printf("Enter the data to be enqueued: ");
    scanf("%d",&x);
    if(isEmpty_S())
        q.queue_S[++q.front] = q.queue_S[++q.rear] = x;
    else
        q.queue_S[++q.rear] = x;
    printf("%d is enqueued into the queue\n",x);
}

void dequeue_S()
{
    if(isEmpty_S())
    {
        printf("Queue is empty\n");
        return;
    }
    int x;
    if(q.front == q.rear)
    {
        x = q.queue_S[q.front];
        q.front = q.rear = -1;
    }
    else
    {
        x = q.queue_S[q.front];
        q.front++;
    }
    printf("%d has been dequeued from the queue\n",x);
}

void peek_S()
{
    if(isEmpty_S())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The front element of the queue is %d\n",q.queue_S[q.front]);
}

int isFull_S()
{
    if(q.rear == (N-1))
        return 1;
    else
        return 0;
}

int isEmpty_S()
{
    if(q.rear == -1 && q.front == -1)
        return 1;
    else
        return 0;
}

void display_S()
{
    if(isEmpty_S())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The elemets of queue is/are: ");
    for(int i = q.front; i <= q.rear; i++)
        printf("%d  ",q.queue_S[i]);
    printf("\n");
}

void Dynamic_Queue()  
{
    int n, choice;
    struct Queue_D q;
    printf("Enter the maximum size of the queue: "); 
    scanf("%d",&n);
    create_D(&q,n);
    menu();
    do
    {
        printf("\nEnter your choice: ");  scanf("%d",&choice);
        switch (choice)
        {
            case 1: enqueue_D(&q); break;
            case 2: dequeue_D(&q); break;
            case 3: peek_D(q); break;
            case 4: display_D(q); break;
            case 0: main(); break;
            case -1: exit(0);
            default : printf("\nInvalid choice!\n");  break;
        }
    }while(choice!=-1);
}


int isEmpty_D(struct Queue_D q)
{
    if(q.front == q.rear)
        return 1;
    else
        return 0;
}

void create_D(struct Queue_D *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->queue_D=(int *)malloc(q->size*sizeof(int));
}

void enqueue_D(struct Queue_D *q)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is Full\n");
        return;
    }
    int x;
    printf("Enter data to be enqueued: "); scanf("%d", &x);
    q->rear++;
    q->queue_D[q->rear]=x;
    printf("%d is enqueued into the queue\n",x);
}

void dequeue_D(struct Queue_D *q)
{
    int x;
    if(q->front == q->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
    x=q->queue_D[q->front];
    printf("%d is enqueued from the queue\n",x);
}

void display_D(struct Queue_D q)
{
    int i;
    if(isEmpty_D(q))
        printf("Queue is Empty\n");
    else
    {
        printf("The element(s) of queue is/are: ");
        for(i = q.front+1; i <= q.rear; i++)
            printf("%d ",q.queue_D[i]);
        printf("\n");
    }
}

void peek_D(struct Queue_D q)
{
    if(isEmpty_D(q))
        printf("Queue is Empty\n");
    else
        printf("The front element of the queue is  %d\n", q.queue_D[q.front+1]);
}