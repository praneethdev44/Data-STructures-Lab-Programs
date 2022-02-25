/*
Problem Description 5 : Develop a menu driven program to implement doubly linked list with various operations such as
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
void ordered_list();
void reverse();
void display();
int getlength();
struct Node* copy_list();
void print_list();

struct Node
{
    int data;
    struct Node *next,*prev;
}*head,*newnode,*ptr,*temp,*p,*q,*dup;

int main()
{
    int ch;
    printf("\n");
    printf("***MAIN MENU***");
    printf("\nEnter\n1->Create doubly linked list\n2->Insertion of node at front\n3->Deletion of node at front\n4->Insertion of node at rear end\n5->Deletion of node at rear end\n6->Insertion of node at specified position\n7->Deletion of node at specified position\n8->Delete a node by Key\n9->Search by Key\n10->Create an ordered list\n11->Reverse a list\n12->Create a copy of the list and display\n13->Display the list\n14->Exit!\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : create_node(); break;
            case 2 : insert_front(); break;
            case 3 : delete_front(); break;
            case 4 : insert_end(); break;
            case 5 : delete_end(); break;
            case 6 : insert_pos(); break;
            case 7 : delete_pos(); break;
            case 8 : delete_by_key(); break;
            case 9 : search_by_key(); break;
            case 10 : ordered_list(); break;
            case 11 : reverse(); break;
            case 12 : dup = copy_list();
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
    printf("\nEnter number of nodes to be created: ");
    scanf("%d",&n);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL)
        printf("Memory not allocated!\n");
    else
    {
        printf("Enter data for NODE-1: ");
        scanf("%d",&newnode->data);
        head = newnode;
        newnode->next = NULL;
        temp = head;
        for(i = 2; i <= n; i++)
        {
            newnode=(struct Node *)malloc(sizeof(struct Node));
            if(newnode==NULL)
                printf("Memory not allocated!\n");
            else
            {
                printf("Enter data for NODE-%d: ",i);
                scanf("%d",&newnode->data);
                temp->next = newnode;
                newnode->prev = temp;
                temp = temp->next;
            }
        }
        temp->next = NULL;
        printf("\nDoubly linked list created.\n");
    }
    display();
}

void insert_front()
{
    newnode=(struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL)
        printf("Memory not allocated!\n");
    else
    {
        printf("Enter data for node : ");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        printf("NODE inserted at beginning!\n");
        display();
    }
    
}
void delete_front()
{
    if(head==NULL) { printf("\nThe list is empty"); }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("NODE deleted from the beginning!\n");
        display();
    }
}
void insert_end()
{
    newnode=(struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL)
        printf("Memory not allocated!\n");
    else {
    temp=head;
    printf("Enter data for node: ");
    scanf("%d",&newnode->data);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    newnode->prev=temp;
    printf("NODE inserted at end!\n");
    display();
    }
}
void delete_end()
{
    if(head==NULL) { printf("The list is empty!\n"); }
    else {
    p=head;
    q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    printf("Last NODE deleted!\n");
    display();
    }

}
void insert_pos()
{
    int pos,i=1,l;
    l=getlength();
    printf("Enter the position at which you want to insert a node: ");
    scanf("%d",&pos);
    if(pos<1 || pos>(l + 1)) { printf("Invalid position!\n"); }
    else if(pos==1) { insert_front(); }
    else if(pos == (l + 1)) {insert_end();} 
    else
    {
        newnode=(struct Node *)malloc(sizeof(struct Node));
        if(newnode==NULL)
            printf("Memory not allocated!\n");
        else {  
        printf("Enter data for node: ");
        scanf("%d",&newnode->data);
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
        printf("NODE inserted at desired position.\n");
        display();
        }
        
    }
    
}
void delete_pos()
{
    if(head==NULL) { printf("The list is empty\n"); }
    else {
    int pos,i=1,l;
    l=getlength();
    printf("Enter the position at which you want to delete a node: ");
    scanf("%d",&pos);
    if(pos<1 || pos>l) { printf("Invalid position!\n"); }
    else if(pos==1) { delete_front(); }
    else if(pos==l) { delete_end(); }
    else
    {
        p=head;
        q=head->next;
        while(i<pos-1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next=q->next;
        q->next->prev=p;
        free(q);
        printf("NODE deleted at desired position.\n");
        display();
    }
    }
    
}
void delete_by_key()
{
    int key;
    if(head==NULL) { printf("The list is empty\n"); }
    else 
    {
        printf("Enter the element which is to be deleted: ");
        scanf("%d",&key);
        p=head;
        q=head->next;
        while(p->next!=NULL)
        {
            if(q->data==key)
            {
                p->next=q->next;
                q->next->prev=p;
                free(q);
                q=q->next;
            }   
            p=p->next;
            q=q->next;
        }
        printf("Key=%d is deleted\n",key);
        display();
    }
}

void search_by_key()
{
    int key,i=0;
    if(head == NULL) {printf("The list is empty\n");}
    else
    {
        printf("Enter the element which is to be searched: ");
        scanf("%d",&key);
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data==key)
            {
            printf("The key %d is found at position-%d\n", key, (i + 1));
            }
            temp=temp->next;
            i++;
        }
        display();
    }
    
}
void ordered_list()
{
    int t;
    struct Node *i,*j;
    if(head == NULL) {printf("The list is empty\n");}
    else {
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
    printf("Now the list is in order\n");
    display();
    }
    
}
void reverse()
{
    struct Node *prevNode,*curNode;
    if(head == NULL) {printf("The list is empty\n");}
    else {
    prevNode=NULL;
    curNode=head;
    while(head!=NULL)
    {
        head=head->next;
        curNode->next=prevNode;
        prevNode=curNode;
        
        curNode=head;
    }
    head=prevNode;
    printf("The list is reversed successfully\n");
    display();
    }
    
}
void display()
{
    if(head == NULL) {printf("\nThe list is empty");}
    else {
    ptr=head;
    printf("\nThe LIST: ");
    while(ptr!=NULL)
    {
        printf("%d <=> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
    printf("\n");
    }
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
    return len;
}
struct Node* copy_list()
{
    struct Node* current = head;   
    struct Node* head1 = NULL;    
    struct Node* tail = NULL; 
    if(head == NULL) {printf("The list is empty\n");}
    else {
 
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
            tail->next->prev=tail;
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
 
    return head1;
    }
}
void print_list()
{
    ptr = dup;
    if(head == NULL) {printf("The list is empty\n");}
    else {
    printf("\nCopied list: ");
    while (ptr)
    {
        printf("%d <=> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    }
}

