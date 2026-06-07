/*To check the given number is perfect number or not using C (A perfect number is a positive integer
 equal to the sum of its proper positive divisors (excluding the number itself))
Example of perfect number are : 6 (divisors: 1, 2, 3 and 1+2+3=6) 
                                28 (divisors: 1, 2, 4, 7, 14 and 1+2+4+7+14=28)  */
 
#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Enter the value of number \n");
    scanf("%d",&n);

    //to store the sum of all the numbers which are divisble to the given number
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        sum=sum+i;
    }
    if(sum==n)
    printf("The given Number %d is perfect number \n",n);
    else
    printf("The given Number %d is not a perfect number \n",n);
    return 0;
}