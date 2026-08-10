/*Write a C program to perform a Linear Search on an array*/

#include<stdio.h>
int main()
{
    int n,i,key=0,count=0,pos=0;
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&key); //element for search
    for(i=0;i<n;i++)
    {
        pos++;       //finding the position in the array
        if(key==arr[i]) //checking if the element is present in the array or not
        {
        count++;
        break;
        }
    }
    if(count==1)
    printf("Yes the element is present in the array in the position %d\n",pos);
    else
    printf("No the element is not present in the array\n");
    return 0;
}