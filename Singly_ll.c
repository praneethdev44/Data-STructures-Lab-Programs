/*
Problem Description 4 : Develop a menu driven program to implement singly linked list with various operations such as
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
void create_node();
void insert_front();
void delete_front();
void insert_end();
void delete_end();
void insert_pos();
void delete_pos();
void delete_by_key();
void search_by_key();
void sort();
void reverse();
void display();
int getlength();
struct Node* copy_list();
void print_list();

struct Node
{
    int data;
    struct Node *next;
}*head,*newnode,*ptr,*temp,*p,*q,*dup;

int main()
{
    int ch;
    printf("\n");
    printf("**********MAIN MENU**********");
    printf("\n1->Create singly linked list\n2->Insertion at front\n3->Deletion at front\n4->Insertion at rear end\n5->Deletion at rear end\n6->Insertion at specified position\n7->Deletion at specified position\n8->Delete by Ke\n9->Search by Key\n10->Create an ordered list\n11->Reverse a list\n12->Create a copy of the list and display\n13->Display the list\n14->Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
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
            case 10: sort(); break;
            case 11: reverse(); break;
            case 12: dup = copy_list();
                    // print duplicate linked list
                    print_list(dup); 
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
    printf("\nEnter number of nodes to be created: ");
    scanf("%d",&n);
    newnode=(struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory not allocated!\n");
    }
    else
    {
        printf("Enter data for NODE 1: ");
        scanf("%d",&newnode->data);
        head=newnode;
        newnode->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
            newnode=(struct Node *)malloc(sizeof(struct Node));
            if(newnode==NULL)
            {
                printf("Memory not allocated!\n");
            }
            else
            {
                printf("Enter data for NODE %d: ",i);
                scanf("%d",&newnode->data);
                temp->next=newnode;
                temp=temp->next;
            }
        }
        temp->next=NULL;
        printf("Singly linked list created.\n");
    }
}
void insert_front()
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
    }
        else
    {
    printf("Enter data: ");
    scanf("%d", &newnode->data);

        newnode->next = head;
        head = newnode;
        printf("NODE inserted at beginning!\n");
    }
}
void delete_front()
{
    q = head;
    head = head->next;
    free(q);
    printf("NODE deleted from the beginning!\n");
}
void insert_end()
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
    }
    p = head;
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newnode;
    newnode->next = NULL;
    printf("NODE inserted at end!\n");
}
void delete_end()
{
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    printf("Last NODE deleted!\n");
}
void insert_pos()
{
    int pos,i=1,l;
    l=getlength();
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
         printf("Memory not allocated\n");
    }
    printf("\nEnter position at which you want to insert new node: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if(pos<1 || pos>l) { printf("Invalid position!\n"); }
    else if(pos==1) { insert_front(); }
    else if(pos==l) { insert_end(); }
    else
    {
        p = head;
        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        newnode->next = p->next;
        p->next = newnode;
        printf("NODE inserted at desired position.\n");
    }
}
void delete_pos()
{
    int pos,i=1,l;
    l=getlength();
    printf("Enter the position at which you want to delete a Node: ");
    scanf("%d", &pos);
    if(pos<1 || pos>l) { printf("Invalid position!\n"); }
    else if(pos==1) { delete_front(); }
    else if(pos==l) { delete_end();  }
    else
    {
        p = head;
        q = head->next;
        while (i < pos - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        free(q);
        printf("NODE deleted at desired position.\n");
    }
}
void delete_by_key()
{
    int key;
    printf("Enter the value that you want to delete. ");
    scanf("%d", &key);
    p = head;
    q = head->next;
    while (p->next != NULL)
    {
        if (q->data == key)
        {
            p->next = q->next;
            free(q);
            q = q->next;
        }
        p = p->next;
        q = q->next;
    }
    printf("Key=%d is deleted.", key);
}
void search_by_key()
{
    temp = head;
    int key, i = 0;
    printf("Enter the value that you want to search. ");
    scanf("%d", &key);
    while (temp!= NULL)
    {
        if (temp->data == key)
        {
            printf("The key %d is found at position %d.", key, (i + 1));
        }
        temp = temp->next;
        i++;
    }
}
void sort()
{
    int t;
    struct Node *i,*j;
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data > j->data)
            {
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
    printf("The list is sorted successfully.");
}
void reverse()
{
    struct Node *prevNode, *curNode;
    if (head != NULL)
    {
        prevNode = NULL;
        curNode = head;
        while (head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }
        head = prevNode;
    }
    printf("The list is reversed successfully.");
}
void display()
{
    struct Node *ptr = head;
    printf("The LIST: ");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
int getlength()
{
    int len=0;
    temp=head;
    if(temp==NULL)
    {
        len=0;
    }
    else
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
    }
    return len++;
}

struct Node* copy_list()
{
    struct Node* current = head;   
    struct Node* head1 = NULL;    
    struct Node* tail = NULL;     
 
    while (current != NULL)
    {
        if (head1 == NULL)
        {
            head1 = (struct Node*)malloc(sizeof(struct Node));
            head1->data = current->data;
            head1->next = NULL;
            tail = head1;
        }
        else 
        {
            tail->next = (struct Node*)malloc(sizeof(struct Node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
 
    return head1;
}
void print_list()
{
    ptr = dup;
    printf("Copied list: ");
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}