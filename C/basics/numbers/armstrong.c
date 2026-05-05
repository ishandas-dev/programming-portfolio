#include<stdio.h>
#include<math.h>
int main()
{
    int n,temp=0,d=0,s=0,c=0;
    printf("Enter the value of number \n ");
    scanf("%d",&n);
    temp=n;
    while(temp>0)
    {
        c++;
        temp=temp/10;
    }
    temp=n;
    while(temp>0)
    {
        d=temp%10;
        s=s+pow(d,c);
        temp=temp/10;
    }
    if(s==n)
    printf("The given number %d is armstrong number \n",n);
    else
    printf("The given number %d is not armstrong number \n",n);
}