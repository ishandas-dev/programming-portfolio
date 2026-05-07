/* To check the given number is even or odd using C*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    if(n%2==0)
    printf("The given number %d is even \n",n);
    else
    printf("The given number %d is odd \n",n);
    return 0;
}