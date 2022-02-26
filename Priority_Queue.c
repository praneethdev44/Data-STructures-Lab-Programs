/* C program to implement priority queue with static and dynamic memory allocation mechanism using  array storage representation
   Name of the program:Priority_Queue.c
*/

#include<stdio.h>
#include<stdlib.h>
#define N 5

struct PQueueS
{
    int front;
    int rear;
    int QS[N];
}q;

struct PQueueD
{
 int size;
 int front;
 int rear;
 int *QD;
};

void StaticPQueue();
void enqueueS();
void dequeueS();
int isEmptyS();
int isFullS();
void peekS();
void displayS();

void DynamicPQueue();
void createD(); 
void enqueueD();
void dequeueD();
int isEmptyD();
void peekD();
void displayD();

void main()
{
    int choice;
    printf("\n*MAIN MENU*\nEnter\n1->To perform priority queue operations using static memory allocation mechanism\n2->To perform  priority queue operations using dynamic memory allocation mechanism\n-1->To exit!\n");
    printf("Enter your choice: ");  scanf("%d", &choice);
    switch(choice)
    {
        case 1: StaticPQueue(); break;
        case 2: DynamicPQueue(); break;
        case -1: exit(0);
        default : printf("Invalid choice\n"); break;
    }
}

void menu()
{
    printf("\n**QUEUE OPERATIONS**\nEnter\n1->To enqueue the element\n2->To dequeue the element\n3->To print the front element of the queue\n4->To display the elememt(s)\n0->Go to main menu\n-1->To exit!\n");
}

void StaticPQueue()
{
    q.front = q.rear = -1;
    int choice;
    menu();
    do
    {
        printf("\nEnter your choice: "); scanf("%d",&choice);
        switch (choice)
        {
            case 1: enqueueS(); break;
            case 2: dequeueS(); break;
            case 3: peekS(); break;
            case 4: displayS(); break;
            case 0: main(); break;
            case -1: exit(0);
            default : printf("\nInvalid choice!\n");  break;
        }
    }while(choice != -1);
}


void enqueueS()
{
    if(isFullS())
    {
        printf("Queue is full\n");
        return;
    }
    int x,i,j,temp;
    printf("Enter the data to be enqueued: ");
    scanf("%d",&x);
    if(isEmptyS())
        q.QS[++q.front] = q.QS[++q.rear] = x;
    else
    {
        for(i = 0; i <= q.rear; i++)
            if(x <= q.QS[i])
                for(j = q.rear + 1; j > i; j--)
                    q.QS[j] = q.QS[j - 1];
            q.QS[i] = x;
            return;
    }
    q.QS[i] = x;
}

void dequeueS()
{
    if(isEmptyS())
    {
        printf("Queue is empty\n");
        return;
    }
     int x = q.QS[q.front];
    if(q.front == q.rear)
    {
        q.front = q.rear = -1;
    }
    else
    {
        for(int i = q.front; i < q.rear; i++)
            q.QS[i] = q.QS[i + 1]; 
    }
    printf("%d has been dequeued from the queue\n",x);
}

void peekS()
{
    if(isEmptyS())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The front element of the queue is %d\n",q.QS[q.front]);
}

int isFullS()
{
    if(q.rear == (N-1))
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

void displayS()
{
    if(isEmptyS())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The elemets of queue is/are: ");
    for(int i = q.front; i <= q.rear; i++)
        printf("%d  ",q.QS[i]);
    printf("\n");
}

void DynamicPQueue()  
{
    int n, choice;
    struct PQueueS q;
    printf("Enter the maximum size of the queue: "); 
    scanf("%d",&n);
    createD(&q,n);
    menu();
    do
    {
        printf("\nEnter your choice: ");  scanf("%d",&choice);
        switch (choice)
        {
            case 1: enqueueD(&q); break;
            case 2: dequeueD(&q); break;
            case 3: peekD(q); break;
            case 4: displayD(q); break;
            case 0: main(); break;
            case -1: exit(0);
            default : printf("\nInvalid choice!\n");  break;
        }
    }while(choice!=-1);
}


int isEmptyD(struct PQueueD q)
{
    if(q.front == q.rear)
        return 1;
    else
        return 0;
}

void createD(struct PQueueD *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->QD=(int *)malloc(q->size*sizeof(int));
}

void enqueueD(struct PQueueD *q)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is Full\n");
        return;
    }
    int x,i,j;
    printf("Enter data to be enqueued: "); scanf("%d", &x);
    if(isEmptyS())
        q->QD[++q->front] = q->QD[++q->rear] = x;
    else
    {
        for(i = q->rear; i>=0 && q->QD[i] > x ; i--)
            q->QD[i+1] = q->QD[i];
        q->QD[i+1] = x;
        q->rear++;
    }
}

void dequeueD(struct PQueueD *q)
{
    if(q->front == q->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    int x = q->QD[q->front];
    if(q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        for(int i = q->front; i < q->rear; i++)
            q->QD[i] = q->QD[i + 1]; 
    }
    printf("%d has been dequeued from the queue\n",x);
}

void displayD(struct PQueueD q)
{
    int i;
    if(isEmptyD(q))
        printf("Queue is Empty\n");
    else
    {
        printf("The element(s) of queue is/are: ");
        for(i = q.front+1; i <= q.rear; i++)
            printf("%d ",q.QD[i]);
        printf("\n");
    }
}

void peekD(struct PQueueD q)
{
    if(isEmptyD(q))
        printf("Queue is Empty\n");
    else
        printf("The front element of the queue is  %d\n", q.QD[q.front]);
}