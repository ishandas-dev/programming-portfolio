/*Write a C program to find the sum, difference, product, and quotient of all elements in an array.
  Take the size and elements of the array as input from the user,then perform each operation across 
  all elements and display the results\*/

#include<stdio.h>
int main()
{
    int n,i;
    float sum=0.0,pro=1.0,diff=0.0,quo;
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    float arr[n];
    printf("Enter the elements in the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=sum+arr[i];
        pro=pro*arr[i];
        if(i==0)
        {
            diff=arr[i];
            quo=arr[i];
        }

        /*subtraction and division don't have a neutral starting value like 1 or 0 ,so the first 
        element just seeds diff and quo instead of being operated*/
        else
        {
            diff=diff-arr[i];  //each number after the first gets subtracted from whatever diff currently holds
            quo=quo/arr[i];    //each number after the first gets divided into whatever quo currently holds
        }
    }
    printf("The sum of the elements of the array is %f \n"
        "The difference of the elements of the array is %f \n"
        "The product of the elements of the array is %f \n"
        "The quotient of the elements of the array is %f ",sum,diff,pro,quo);
    return 0;
}