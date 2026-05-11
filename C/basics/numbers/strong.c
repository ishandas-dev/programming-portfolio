#include<stdio.h>
int main()
{
    int n,fact=1,i,temp=0,digit=0,sum=0;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    temp=n;
    while(temp>0)
    {
        digit=temp%10;
        for(i=1;i<=digit;i++)
        {
            fact=fact*i;
        }
        sum=sum+fact;
        fact=1;
        temp=temp/10;
    }
    if(n==sum)
    printf("The given number %d is a strong number as it's sum of its digit's factorial is also %d \n",n,sum);
    else
    printf("The given number %d is not a strong number as it's sum of its digit's factorial is also %d \n",n,sum);
}