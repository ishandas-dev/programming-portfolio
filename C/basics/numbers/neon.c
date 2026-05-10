/*To check the given number is Neon number or not using C*/
#include<stdio.h>
int main()
{
    int n,square,temp=0,digit=0,sum=0;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    square=n*n;
    temp=square; //using temporary variable to store the square of the given number

    //storing the sum of the digits of the square of given number
    while(temp>0)
    {
        digit=temp%10;
        sum=sum+digit;
        temp=temp/10;
    }
    if(sum==n)
    printf("The given number %d is a neon number as it's square is %d whose digit's sum is %d itself \n",n,square,sum);
    else
    printf("The given number %d is not a neon number as it's square is %d whose digit's sum is %d \n",n,square,sum);
    return 0;
}