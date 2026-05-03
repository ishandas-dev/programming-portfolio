#include<stdio.h>
int main()
{
    int n,d=0,rev=0,temp=0;
    printf("Enter the number \n");
    scanf("%d",&n);
    temp=n;
    while(temp>0)
    {
        d=temp%10;
        rev=rev*10+d;
        temp=temp/10;
    }
    if (n==rev)
    printf("the given number %d is a palindrome \n",n);
    else
    printf("the given number %d is not a palindrome \n",n);
    return 0;
}
    