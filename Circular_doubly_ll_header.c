/*
Problem Statement 3 : Develop a menu driven program to implement Circular Doubly linked list with Header node to perform various operations such as
i) Insertion and Deletion at front/rear
ii) Insertion and Deletion at the specified position
iii) Delete by Key
iv) Search by key
v) Create an ordered list
vi) Reverse a list
vii) Creating a copy of the list
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void create_node();
void insert_front();
void delete_front();
void insert_end();
void delete_end();
void insert_pos();
void delete_pos();
void delete_by_key();
void search_by_key();
void ordered_list();
void reverse();
void display();
int getlength();
struct Node* copy_list();
void print_list();
void header_data();

struct Node
{
    int data;
    struct Node *next,*prev;
}*head,*newnode,*ptr,*temp,*p,*q,*tail,*dup;

struct HeaderNode
{
    int counter;
    int max,min;
    struct Node *next;
}*header;

int count = 0;

int main()
{
    int ch;

    printf("\n******MAIN MENU******\n1->Create Circular Doubly Linked List\n2->Insertion at front\n3->Deletion at front\n4->Insertion at rear end\n5->Deletion at rear end\n6->Insertion at specified position\n7->Deletion at specified position\n8->Delete by Key\n9->Search by Key\n10->Create an ordered list\n11->Reverse a list\n12->Create a copy of the list and display\n13->Display the list\n14->Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
	if(ch == 1) { count = 0;}
        switch(ch)
        {
            case 1: create_node(); break;
            case 2: insert_front(); break;
            case 3: delete_front(); break;
            case 4: insert_end(); break;
            case 5: delete_end(); break;
            case 6: insert_pos(); break;
            case 7: delete_pos(); break;
            case 8: delete_by_key(); break;
            case 9: search_by_key(); break;
            case 10: ordered_list(); break;
            case 11: reverse(); break;
            case 12: dup = copy_list();
                     // print duplicate linked list
                     if(dup != NULL)
                        print_list(); 
                     break;
            case 13: display(); break;
            case 14: break;   
        }         
    }while(ch!=14);
    return 0;
}
void create_node()
{
    int i,n;
    header = (struct HeaderNode*)malloc(sizeof(struct HeaderNode));
    printf("Enter number of nodes to be created: ");
    scanf("%d",&n);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if(newnode == NULL)
        printf("Memory not allocated!\n");
    else
    {
        header->next = newnode;
        printf("Enter data for NODE-1: ");
        scanf("%d",&newnode->data);
        head = newnode;
        newnode->next = newnode->prev = head;
        count++;
        temp = head;
        for(i=2;i<=n;i++)
        {
            newnode=(struct Node *)malloc(sizeof(struct Node));
            if(newnode==NULL)
                printf("Memory not allocated!\n");
            else
            {
                printf("Enter data for NODE-%d: ",i);
                scanf("%d",&newnode->data);
                temp->next = newnode;
                newnode->prev=temp;
                temp = temp->next;
                count++;
            }
        }
        temp->next = head;
        head->prev = temp;
        printf("Circular doubly linked list created!\n");
    }
    header_data();
    display();
}

void insert_front()
{
    newnode=(struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL)
        printf("Memory not allocated!\n");
    else
    {
        printf("Enter data for the NODE: ");
        scanf("%d",&newnode->data);
        head->prev->next=newnode;
        newnode->prev=head->prev;
        newnode->next=head;
        head->prev=newnode;
        head = newnode;
        header->next = head;
        printf("NODE inserted at the beginning!\n");
        count++;
        header_data();
        display();
    }
}
void delete_front()
{
    if(head == NULL) 
        printf("The list is empty!\n");
    else 
    {
        if(count == 1)
        {
            temp = head;
            header->next = head = NULL;
        }
        else
        {
            temp = head;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            head = temp->next;
            header->next = head;
        }
        free(temp);
        printf("NODE deleted from the beginning!\n");
        count--;
        header_data();
        display();
    }
}

void insert_end()
{
    newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory not allocated!\n");
        return;
    }
    printf("Enter data for the NODE: ");
    scanf("%d",&newnode->data);
    if(head == NULL)
    {
        head = newnode;
        newnode->next = newnode->prev = header->next= head;
       
    }
    else
    {
        newnode->prev = head->prev;
        newnode->next=head;
        head->prev->next = newnode;
        head->prev = newnode;
    }
    printf("NODE inserted at end!\n");
    count++;
    header_data();
    display();
}
void delete_end()
{
    if(head==NULL) 
        printf("The list is empty!\n"); 
    else 
    {
        if(count == 1)
        {
            temp = head;
            header->next = head = NULL;
        }
        else
        {   
            temp=head->prev;
            temp->prev->next = head;
            head->prev = temp->prev;
        }
        free(temp);
        printf("Last NODE deleted!\n");
        count--;
        header_data();
        display();
    }
}

void insert_pos()
{
    int pos,i=1,l;
    l=getlength();    
    printf("Enter the position at which the node has to be inserted: ");
    scanf("%d",&pos);
    if(pos<1 || pos>(l+1)) 
        printf("Invalid position!\n");
    else if(pos==1) 
        insert_front(); 
    else if(pos == (l +1))
        insert_end();
    else
    {
        newnode=(struct Node *)malloc(sizeof(struct Node));
        if(newnode==NULL)
            printf("Memory not allocated!\n");
        printf("Enter data for the NODE: ");
        scanf("%d",&newnode->data);
        temp = head;
        while(i <(pos-1))
        {
            temp=temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
        printf("NODE inserted at position-%d\n",pos);
        count++;
        header_data();
        display();
    }
}

void delete_pos()
{
    if(head==NULL) 
    {
        printf("The list is empty"); 
        return;
    }
    int pos,i=1,l;
    l=getlength();
    printf("Enter a position at which the node has to be deleted: ");
    scanf("%d", &pos);
    if(pos<1 || pos>l) 
        printf("Invalid position!\n"); 
    else if(pos==1) 
        delete_front(); 
    else if(pos==l) 
        delete_end();
    else
    {
        p = head;
        q = head->next;
        while(i< (pos-1))
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        q->next->prev = p;
        free(q);
        printf("NODE deleted at position-%d\n",pos);
        count--;
        header_data();
        display();
    }
}

void delete_by_key()
{
    if(head==NULL)  
    {
        printf("The list is empty!\n");
        return;
    } 
    int key;
    printf("Enter the element to be deleted: ");
    scanf("%d",&key);
    if(head->data == key)
    {
        temp = head;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        head = temp->next;
        header->next = head;
        free(temp);
    }
    else
    {
        p = head;
        q = head->next;
        while(p->next != head)
        {
            if(q->data==key)
            {
                p->next=q->next;
                free(q);
                q=q->next;
            }
            p=p->next;
            q=q->next;
        }
    }
    printf("Key=%d is deleted\n", key);
    count--;
    header_data();
    display();
}

void search_by_key()
{
    if(head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    int key,i = 1,found = 0;;
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    temp = head;
    while(i <= count)
    {
        if(temp->data == key)
        {
            printf("%d is found at position-%d\n", key,i);
            found = 1;
        }
        i++;
        temp = temp->next;
    }
    if(!found)
        printf("%d is not found in the list\n",key);
    display();
}

void ordered_list()
{
    int t;
    struct Node *i,*j;
    for(i=head;i->next!=head;i=i->next)
    {
        for(j=i->next;j!=head;j=j->next)
        {
            if(i->data > j->data)
            {
                t=i->data;
                i->data=j->data;
                j->data=t;
            }           
        }
    }
    printf("Now the list is in order\n");
    display();
}

void reverse()
{
    struct Node *prevNode=head,*curNode=head,*temp=head;
    curNode=head;
    curNode=curNode->next;
    temp=temp->next->next;
    while(curNode!=head)
    {
        curNode->next=prevNode;
        prevNode=curNode;
        curNode=temp;
        temp=temp->next;
    }
    head=prevNode;
    curNode->next=head;
    printf("The list is reversed successfully\n");
    display();
}
void display()
{
    printf("The LIST: ");
    if(header->next==NULL)
    {
        printf("[%d] <=> NULL",header->counter);  
    }
    else
    {
        printf("[%d,%d,%d] <=> ",header->counter,header->min,header->max);
        temp=head;
        while(temp->next!=head)
        {
            printf("[%d] <=> ",temp->data);
            temp=temp->next;
        }
        printf("[%d] <=>\n ",temp->data);
    }
}

int getlength()
{
    int len = 0;
    if(temp==NULL)
        head = 0;
    else
    {
        temp = head;
        while(temp->next != head)
        {
            temp=temp->next;
            len++;
        }
        len++;
    }
    return len;
}
struct Node* copy_list()
{
    if(head == NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    else
    {
        struct Node* current = head;   
        struct Node* head1 = NULL;    
        struct Node* tail = NULL;     
        do
        {
            if (head1 == NULL)
            {
                head1 = (struct Node*)malloc(sizeof(struct Node));
                head1->data = current->data;
                head1->next = head1;
                tail = head1;
            }
            else 
            {
                tail->next = (struct Node*)malloc(sizeof(struct Node));
                tail = tail->next;
                tail->data = current->data;
                tail->next = head1;
            }
            current = current->next;
        }while (current!= head);
        return head1;
    }
}
void print_list()
{
    struct Node *head1;
    printf("Copied list: ");
    printf("[%d,%d,%d] <=> ",header->counter,header->min,header->max);
    ptr = head1; 
    while (ptr->next!=head1)
    {
        printf("[%d] <=> ", ptr->data);
        ptr = ptr->next;
    }
    printf("[%d] <=>\n ",ptr->data);
}

void header_data()
{
    header->min=INT_MAX;
    header->max=INT_MIN;
    temp=head;
    do
    {
        if(header->min > temp->data) 
            header->min=temp->data;
        if(header->max < temp->data) 
            header->max=temp->data;
        temp=temp->next;
    }while(temp!=head);
    header->counter = getlength();
}

