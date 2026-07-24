/*Write a program IN C to find the largest number in an array.Take the size and elements of the array 
as input from the user, then traverse the array to find the maximum element*/

#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]); //entering the elements in the array
    }
    int max = arr[0];  //assume first element is the largest to start
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
           max=arr[i];   //update max whenever a bigger element is found
        }
    }
    printf("The largest number in the array is %d \n",max);
    return 0;
}