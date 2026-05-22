/*An alternating series is an infinite series where the signs of the terms continually flip back and 
forth between positive and negative like sum of (1-2+3-4+5-6...till n)*/

#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
        sum=sum-i;
        else
        sum=sum+i;
    }
    printf("The sum of Alternate series for given number %d is %d",n,sum);
    return 0;
}

