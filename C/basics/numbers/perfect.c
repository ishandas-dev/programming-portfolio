/*To check the given number is perfect number or not using C*/
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
}