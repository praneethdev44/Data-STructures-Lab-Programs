/*
Problem Statement 2: Define a structure called Time containing 3 integer members (hour,minute, second). Develop a menu driven program to perform the following by writing separate function for each operation.
a) To read time b) To display time c) To Update time d) Add two times by writing Add (T1, T2) which returns the new Time.
Update function increments the time by one second and returns the new time (if the increment results in 60 seconds, then the second member is set to zero and minute member is incremented by one. If the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour becomes 24, Time should be reset to zero)
Note: Illustrate the use of pointer to a structure variable and passing and returning of structure type to and from the function (both by value and reference)
*/

#include<stdio.h>
#include<stdlib.h>

struct Time
{
    int hour,minute,second;
};

struct Time* read_time(struct Time*);
struct Time* read_time2(struct Time*, struct Time*);
void display_time(struct Time*);
void update_time(struct Time*);

void main()
{
    struct Time *T1, *T2;
    int ch;
    printf("\n\n**********MAIN MENU**********\nEnter\n1->To read time\n2->To display time\n3->To update time\n4->To add two times\n5->To exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : T1 = read_time(T1); break;
            case 2 : printf("TIME:");
                     display_time(T1);
                     break;
            case 3 : T1->second += 1;
                     update_time(T1); 
                     printf("Time is updated now\nUPDATED TIME:");
                     display_time(T1);
                     break;
            case 4 : T2 = read_time2(T1,T2); 
                     break;
            case 5 : exit(0);
            default : printf("Invalid choice......\n"); break;
        }
    }
}

struct Time* read_time(struct Time *T1)
{
    T1 = (struct Time *)malloc(sizeof(struct Time));
    if(T1 == NULL)
        printf("Memory allocation failed\n");
    else
    {
        printf("Enter time (in HH:MM:SS format) : ");
        scanf("%d%d%d",&T1->hour,&T1->minute,&T1->second);
        update_time(T1);
    }
    return T1;
}

struct Time* read_time2(struct Time* T1, struct Time* T2)
{
    T2 = (struct Time *)malloc(sizeof(struct Time)); 
    if(T2 == NULL)
        printf("Memory allocation failed\n");
    else
    {
	    printf("Enter the new time to be added (in HH:MM:SS format) : ");
        scanf("%d%d%d",&T2->hour,&T2->minute,&T2->second);
        T1->second += T2->second;
        T1->minute += T2->minute;
        T1->hour += T2->hour;
        printf("The new time has been added to the previous time");
        update_time(T1);
        printf("\nNEW TIME:");
        display_time(T1);
    }
    return T2;
}

void update_time(struct Time* T1)
{
    while(T1->second >= 60)
    {
        T1->second -= 60;
        T1->minute += 1;
    }
    while(T1->minute >= 60)
    {
        T1->minute -= 60;
        T1->hour += 1;
    }
    while(T1->hour >= 24)
        T1->hour -= 24;
}

void  display_time(struct Time* T1)
{
    printf(" %02d:%02d:%02d Hrs\n",T1->hour,T1->minute,T1->second);
}