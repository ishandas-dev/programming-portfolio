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
    free(ptr);

    //using Calloc
    printf("Enter the value of n for calloc \n");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
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
    ptr=(int*)realloc(ptr,n*sizeof(int));
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