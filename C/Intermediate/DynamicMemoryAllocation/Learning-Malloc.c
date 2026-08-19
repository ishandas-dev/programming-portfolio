/*Write a C program to demonstrate dynamic memory allocation using malloc(), calloc(), and 
realloc(). Take the size and elements as input from the user for each case, and display the 
allocated values. Free the allocated memory appropriately, and check thereturn value of each 
allocation function to handle allocation failure safely.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    int* ptr;

    //using malloc
    printf("Enter the value of n for malloc \n");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));   
    if(ptr==NULL)
    {
        printf("Memory allocation failed (Malloc)\n");
        return 1;
    }
    printf("Enter the elements for malloc \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("values allocated using malloc \n");
    for(i=0;i<n;i++)
    {
        printf("At %d index the value stored is %d \n",i,ptr[i]);
    }
    free(ptr);  //freeing the the ptr before using it below

    //using Calloc
    printf("Enter the value of n for calloc \n");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory allocation failed (calloc)\n");
        return 1;
    }
    printf("Enter the elements for calloc \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("values allocated using calloc: \n");
    for(i=0;i<n;i++)
    {
        printf("At %d index the value is %d \n",i,ptr[i]);
    }
    
    //using Realloc
    printf("Enter the value of new n you want to create with realloc\n");
    scanf("%d",&n);
    int* temp = (int*)realloc(ptr,n*sizeof(int));   //storing result in temp first,so ptr could not be overwrite
    if(temp==NULL)
    {
        printf("Memory allocation failed (realloc)\n");
        free(ptr);    //realloc failed,so the original block is still valid and must be freed 
        return 1;
    }
    ptr=temp;    //safe to update ptr only after confirming realloc succeeded
    printf("Enter the elements for realloc\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("values allocated using realloc: \n");
    for(i=0;i<n;i++)
    {
        printf("At %d index the value is %d \n",i,ptr[i]);
    }
    free(ptr);
    return 0;
}