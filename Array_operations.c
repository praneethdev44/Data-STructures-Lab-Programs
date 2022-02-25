/*
Problem Statement 3 : Develop a menu driven program to implement various operations on array storage representation with static and dynamic memory allocation
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int n; 

void staticmemoryallocation();
void SreadInfo(int a[]);
void SprintInfo(int a[]);
void Supdate(int a[]);
void SinsertSpecified(int a[]); 
void SdeleteSpecified(int a[]);
void Ssearch(int a[]); 
void Ssort(int a[]);

void dynamicmemoryallocation();
void DreadInfo(int *ptr);
void DprintInfo(int *ptr);
void Dupdate(int *ptr);
void DinsertSpecified(int *ptr); 
void DdeleteSpecified(int *ptr);
void Dsearch(int *ptr); 
void Dsort(int *ptr);

int main() {
    int choice;
    printf("\nEnter\n1->To perform array operations using Static Memory Allocation\n2->To perform array operations using Dynamic Memory Allocation\n0->To exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice) {
        case 1 : staticmemoryallocation(); break;
        case 2 : dynamicmemoryallocation(); break;
        case 0 : exit(0); break;
        default : printf("\nInvalid choice"); break;
    }
    return 0;
}

void staticmemoryallocation() {
    int a[MAX],choice;
    start:
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    if(n > MAX ) {
        printf("Overflow Condition....\nThe maximum size of array is limited to %d\n",MAX);
        goto start;
    }
    else if(n < 1) {
        printf("Invalid size of an array\n");
        goto start;
    }
    printf("\nEnter\n1->To read the elements of array\n2->To print the elements of array\n3->To update an element in arry\n4->To insert an element at specified position in array\n5->To delete an element at specified position in an array\n6->To search an element in an array\n7->To sort the elements of array\n8->Go to main menu\n9->To exit\n");
    while(1) {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice) {
            case 1 : SreadInfo(a); break;
            case 2 : SprintInfo(a); break;
            case 3 : Supdate(a); break;
            case 4 : SinsertSpecified(a); break;
            case 5 : SdeleteSpecified(a); break;
            case 6 : Ssearch(a); break;
            case 7 : Ssort(a); break;
            case 8 : main(); break;
            case 9 : exit(0); break;
            default : printf("Invalid choice"); break;
        }
    }
}

void SreadInfo(int a[]){
    int i;
    printf("\nEnter the elements of the array:");
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
}

void SprintInfo(int a[]) {
    int i;
    if(n !=0)
    {
        printf("\nThe elements of the array are:");
        for(i = 0; i < n; i++)
            printf("%d ",a[i]);
    }
    else
        printf("\nThere are no elements in array\n");
}

void Supdate(int a[]) {
    int item,pos,ele;
    repeat:
    printf("\nEnter the position at which the element has to be updated: ");
    scanf("%d",&pos);
    if((pos < 1) || (pos > n)) {
        printf("Element can only be updated anywhere from position-1 to position-%d\n",n);
	    goto repeat;
    }
    printf("\nEnter the value: ");
    scanf("%d",&ele);
    item = a[pos - 1];
    a[pos - 1] = ele;
    printf("\n%d has been successfully replaced by %d\n",item,ele);
    SprintInfo(a);
}
    
void SinsertSpecified(int a[]) {
    int pos,ele,i;
    repeat1:
    printf("\nEnter the position at which the element has to be inserted: ");
    scanf("%d",&pos);
    if(n == MAX) {
        printf("\nInsertion of an element failed due to insufficient memory allocation for the array");
        goto end;
    }
    if((pos < 1) || (pos > (n+1))) {
        printf("\nElement can only be inserted anywhere from position-1 to position-%d\n",(n + 1));
	    goto repeat1;
    }
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&ele);
    for(i = (n-1); i >= (pos - 1); i--)
        a[i + 1] = a[i];
    a[pos - 1] = ele;
    n++;
    printf("%d is insereted successfully at position-%d\n",ele,pos);
    end:
    SprintInfo(a);
}

void SdeleteSpecified(int a[]) {
    int pos,ele,i;
    if(n ==0)
        SprintInfo(a);
    else
    {
        repeat2:
        printf("\nEnter the position of the element to be deleted: ");
        scanf("%d",&pos);
        if((pos < 1) || (pos > n)) 
        {
            printf("\nElement can only be deleted from position-1 to position-%d\n",n);
	        goto repeat2;
        }
        ele = a[pos -1];
        for(i = (pos-1); i < (n - 1); i++)
            a[i] = a[i + 1];
        n--;
        printf("\nThe element %d has been successfully deleted from position-%d\n",ele,pos);
        SprintInfo(a);
    }
}

void Ssearch(int a[]) {
    int key,i,found = 0;
    printf("\nEnter the key element to be searched:");  
    scanf("%d",&key);
    for(i=0; i<n; i++) {
    	if(key==a[i]) {
    	    printf("SEARCH SUCCESSFULL.....\n%d is found at position %d\n",key,i+1);
            found=1;
	        break;
    	}
    }
    if(!found)
    	printf("SEARCH UNSUCCESSFULL.....\n%d is not found in the array\n",key);
    SprintInfo(a);
}

void Ssort(int a[]) {
    int j,temp,i;
    for(i=0; i<(n-1); i++)
    	for(j=0; j<(n-1-i); j++)
	       if(a[j] > a[j+1])
	       {
		        temp = a[j];
   		        a[j] = a[j+1];
		         a[j+1] = temp;
           }
    printf("\nSorted array:");
    for(i=0; i<n; i++)
    	printf("%d  ",a[i]);
    printf("\n");
}

void dynamicmemoryallocation() {
    int choice,*ptr = NULL;
    start4:
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    if(n < 1) {
        printf("Invalid size of an array\n");
        goto start4;
    }
    ptr = (int *)malloc(n * sizeof(int));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        main();
    }
    printf("\nEnter\n1->To read the elements of array\n2->To print the elements of array\n3->To update an element in array\n4->To insert an element at specified position in array\n5->To delete an element at specified position in an array\n6->To search an element in an array\n7->To sort the elements of array\n8->Go to main menu\n9->To exit\n");
    while(1) {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice) {
            case 1 : DreadInfo(ptr); break;
            case 2 : DprintInfo(ptr); break;
            case 3 : Dupdate(ptr); break;
            case 4 : DinsertSpecified(ptr); break;
            case 5 : DdeleteSpecified(ptr); break;
            case 6 : Dsearch(ptr); break;
            case 7 : Dsort(ptr); break;
            case 8 : main(); break;
            case 9 : exit(0); break;
            default : printf("\nInvalid choice"); break;
        }
    }
}

void DreadInfo(int *ptr) {
    int i;
    printf("\nEnter the elements of the array:");
        for(i=0; i<n; i++)
            scanf("%d",(ptr + i));
}

void DprintInfo(int *ptr) {
    int i;
    if(n != 0 )
    {
        printf("\nThe elements of the array are:");
            for(i=0; i<n; i++)
                printf("%d ",*(ptr + i));
    }
    else
    printf("\nThere are no elements in array");
    printf("\n");
}

void Dupdate(int *ptr) {
    int item,pos,ele;
    repeat4:
    printf("\nEnter the position at which the element has to be updated: ");
    scanf("%d",&pos);
    if((pos < 1) || (pos > n)) {
        printf("Element can only be updated anywhere from position-1 to position-%d\n",n);
	    goto repeat4;
    }
    printf("\nEnter the value: ");
    scanf("%d",&ele);
    item = ptr[pos - 1];
    ptr[pos - 1] = ele;
    printf("\n%d has been successfully replaced by %d\n",item,ele);
    DprintInfo(ptr);
}
    
void DinsertSpecified(int *ptr) {
    int pos,ele,i;
    repeat5:
    printf("\nEnter the position at which the element has to be inserted: ");
    scanf("%d",&pos);
    if((pos < 1) || (pos > (n+1))) {
        printf("Element can only be inserted anywhere from position-1 to position-%d\n",(n + 1));
	    goto repeat5;
    }
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&ele);
    n++;
    for(i = (n-1); i >= (pos - 1); i--)
        ptr[i + 1] = ptr[i];
    ptr[pos - 1] = ele;
    printf("\nThe element %d has been successfully inserted at position-%d\n",ele,pos);
    DprintInfo(ptr);
}

void DdeleteSpecified(int *ptr) {
    int pos,ele,i;
    if(n == 0)
        printf("\nThere are no elements in array");
    else
    {
        repeat6:
        printf("\nEnter the position of the element to be deleted: ");
        scanf("%d",&pos);
        if((pos < 1) || (pos > n)) {
            printf("Element can only be deleted from position-1 to position-%d\n",n);
	        goto repeat6;
        }
        ele = ptr[pos -1];
        for(i = (pos-1); i < (n - 1); i++)
            ptr[i] = ptr[i + 1];
        n--;
        printf("\nThe element %d has been successfully deleted from position-%d\n",ele,pos);
        DprintInfo(ptr);
    }
}

void Dsearch(int *ptr) {
    int i,key,found = 0;
    printf("\nEnter the key element to be searched:");  
    scanf("%d",&key);
    for(i=0; i<n; i++)
    	if(key==ptr[i]) {
    	    printf("SEARCH SUCCESSFULL.....\n%d is found at position %d\n",key,i+1);
            found=1;
	        break;
    	}
    if(!found)
    	printf("SEARCH UNSUCCESSFULL.....\n%d is not found in the array\n",key);
    DprintInfo(ptr);
}

void Dsort(int *ptr) {
    int i,j,temp;
    for(i=0; i<(n-1); i++)
    	for(j=0; j<(n-1-i); j++)
	       if(ptr[j] > ptr[j+1])
	       {
		      temp = ptr[j];
   		      ptr[j] = ptr[j+1];
		      ptr[j+1] = temp;
           }
    printf("\nSorted array:");
    for(i=0; i<n; i++)
    	printf("%d  ",ptr[i]);
}