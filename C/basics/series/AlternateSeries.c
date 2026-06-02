/*An alternating series is an infinite series where the signs of the terms continually flip back and 
forth between positive and negative like sum of (1-2+3-4+5-6...till n)*/

#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    printf("The series looks like this :");
    for(i=1;i<=n;i++)
    {
        if(i==1) 
        {
        printf(" %d",i); //printing the first number of the series
        sum=sum+i;
        }
        else if(i%2==0) //checking for even and odd
        {
        printf(" - %d",i); //printing the series
        sum=sum-i; //calculating the sum
        }
        else
        {
        printf(" + %d",i); //printing the series
        sum=sum+i; //calculating the sum
        }
    }
    printf("\nThe sum of Alternate series for given number %d is %d \n",n,sum);
    return 0;
}

