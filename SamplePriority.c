#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef struct queue
{
	int items[size];
	int f,r;
}Q;

void enqueue(Q *q)
{
	int item,i;
	if(q->r == size-1)
	{
		printf("Queue is full\n");
		return;
	}
	printf("Enter the element\n");
		scanf("%d",&item);
	for(i=q->r; i>=0 && q->items[i] > item; i--)
		q->items[i+1] = q->items[i];
	q->items[i+1] = item;
	q->r++;
}

void dequeue(Q *q)
{
	if(q->f > q->r)
	{
		printf("The queue is empty\n");
		return;
	}
	printf("%d is deleted\n",q->items[q->f]);
	q->f++;
	if(q->f > q->r)
	{
		q->f = 0;
		q->r = -1;
	}
}


void disp(Q q)
{
	if(q.f > q.r){
		printf("The queue is empty\n");
		return;
	}
	int i;
	printf("Displaying\n");
	for(i=q.f;i<=q.r;i++)
		printf("%2d\n",q.items[i]);
}



void main()
{
	Q q;
	q.f = 0;
	q.r = -1;
	
	int ch;
	
	while(1)
	{
		printf("Implementation of priority queue\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
			scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				enqueue(&q);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				disp(q);
				break;
			default:
				exit(1);
		}
	}
}


#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef struct queue{
	int items[size];
	int f,r;
}Q;

void insertfront(Q *q){
	int item;
	if(q->f==0 && q->r==-1){
		printf("Enter the element\n");
			scanf("%d",&item);
		q->r++;
		q->items[q->r] = item;

	}
	else if(q->f!=0){
		printf("Enter the element\n");
			scanf("%d",&item);
		q->f--;
		q->items[q->f] = item;
	}
	else
		printf("Insertfront is not possible\n");
}

void insertrear(Q *q){
	int item;
	if(q->r == size-1){
		printf("Queue is full\n");
		return;
	}
	printf("Enter the element\n");
		scanf("%d",&item);
	q->r++;
	q->items[q->r] = item;
}

void delrear(Q *q){
	if(q->f > q->r){
		printf("Queue is empty\n");
		return;
	}
	printf("%d is deleted\n",q->items[q->r]);
	q->r--;
	if(q->f > q->r){
		q->f = 0;
		q->r = -1;
	}
}

void delfront(Q *q){
	if(q->f > q->r){
		printf("Queue is empty\n");
		return;
	}
	printf("%d is deleted\n",q->items[q->f]);
	q->f++;
	if(q->f > q->r){
		q->f = 0;
		q->r = -1;
	}
}

void disp(Q *q){
	if(q->f > q->r){
		printf("Queue is empty\n");
		return;
	}
	int i;
	for(i=q->f;i<=q->r;i++)
		printf("%d\n",q->items[i]);
	
}


void main()
{
	Q q;
	q.f = 0;
	q.r = -1;
	
	int ch;
	
	while(1)
	{
		printf("Implementation of double ended queue\n");
		printf("1.Insert front\n");
		printf("2.Insert rear\n");
		printf("3.Delete front\n");
		printf("4.Delete rear\n");
		printf("5.Display\n");
			scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				insertfront(&q);
				break;
			case 2:
				insertrear(&q);
				break;
			case 3:
				delfront(&q);
				break;
			case 4:
				delrear(&q);
				break;
			case 5:
				disp(&q);
				break;
			default:
				exit(1);
		}
	}
}