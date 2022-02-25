/*
    Problem Description 1 : Define a structure called Student with the members: name, reg_no, marks in 3 tests and average_ marks.Develop a menu driven program to perform the following by writing separate function for each operation: a) read information of N students b) display student’s information c) to calculate the average of best two test marks of each student.
    Note: Illustrate the use of pointer to an array of structure and allocate memory dynamically using malloc() /calloc()/realloc().
*/

#include<stdio.h>
#include<stdlib.h>

struct Student
{
    unsigned int reg_no;
    char name[25];
    int t1,t2,t3;
    float avg,total,small;
}*ptr = NULL;

void read_Info(int n);
void print_Info(int n);
void avg_marks(int n);

int main()
{
    int c, n;
    printf("\nEnter number of students:");
    scanf("%d",&n);
    printf("\nEnter\n1->To read students' information\n2->To print students' information\n3->To print average marks scored by students'(considering best of 2 tests)\n4->To exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: read_Info(n);  break;
            case 2: print_Info(n);  break;
            case 3: avg_marks(n); break;
            case 4: exit(0); break;
            default:printf("\nInvalid choice");  break;
        }
    }
    return 0;
}

void read_Info(int n)
{
    int i;
    ptr = (struct Student *)malloc(n * sizeof(struct Student));
    for(i = 0 ;i < n; i++)
    {
        printf("\nEnter details of student-%d",i+1);
        printf("\nName: ");
        scanf("%s",ptr->name);
        printf("Reg. No. : "); 
        scanf("%d",&ptr->reg_no);
        printf("Marks scored in test-1: ");
        scanf("%d",&ptr->t1);
        printf("Marks scored in test-2: ");
        scanf("%d",&ptr->t2);
        printf("Marks scored in test-3: ");
        scanf("%d",&ptr->t3);
        ptr++;
    }
    ptr -= n;
}

void print_Info(int n)
{   
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nDetails of student-%d",i+1);
        printf("\nName: %s",ptr->name);
        printf("\nReg. No. : %d", ptr->reg_no);
        printf("\nMarks in Test-1: %d",ptr->t1);
        printf("\nMarks in Test-2: %d",ptr->t2);
        printf("\nMarks in Test-3: %d\n",ptr->t3);
        ptr++;
    }
    ptr -= n;
}

void avg_marks(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        ptr->total = ptr->t1 + ptr->t2 + ptr->t3;
        ptr->small = ptr->t1 < ptr->t2 ? (ptr->t1 < ptr->t3 ? ptr->t1 : ptr->t3) : (ptr->t2 < ptr->t3 ? ptr->t2 : ptr->t3);
        ptr->avg = (ptr->total - ptr->small)/2;
        printf("\nAverage marks of student-%d is %.2f", i+1,ptr->avg);
        ptr++;
    }
    ptr -= n ;
}
