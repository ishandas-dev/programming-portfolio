/*Write a C program to read 'n' integers into an array and:
  1.Print all the even numbers present in the array
  2.Print all the odd numbers present in the array
  3.Print the total count of even numbers and odd numbers in the array*/

#include<Stdio.h>
int main()
{
    int n,i,even=0,odd=0;
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    int arr[n];  //creating array of size n
    printf("Enter the elements in the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The even numbers present in the array are: ");
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0) //checking for even numbers
        {
            if(even!=0)   //checking if the current number is first even number or not
            printf(", "); //adding commas before the number for the even series
            printf("%d",arr[i]); //printing the even series
            even++;     //counting the even numbers
        }
    }   
    printf("\nThe odd numbers present in the array are: ");
    for(i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
        {
            if(odd!=0)    //checking if the current number is first odd number or not
            printf(", "); //adding commas before the number for the odd series
            printf("%d ",arr[i]);  //printing the odd series
            odd++;    //counting the odd numbers
        }
    }
    printf("\nNumber of Even numbers in the array are : %d \n",even);
    printf("Number of Odd numnbers in the array are : %d \n",odd);
    return 0;
}
