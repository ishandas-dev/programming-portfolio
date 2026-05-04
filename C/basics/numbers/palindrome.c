/* To check the given number is palindrome number or not using C*/
#include<stdio.h>
int main()
{
    int n,d=0,rev=0,temp=0;
    printf("Enter the number \n");
    scanf("%d",&n);
    temp=n; //using temporary variable to save the original number 
    while(temp>0)
    {
        d=temp%10; //extracting the last digit of the number
        rev=(rev*10)+d; //reversing the number
        temp=temp/10; //removing the last digit
    }
    if (n==rev)
    printf("the given number %d is a palindrome \n",n);
    else
    printf("the given number %d is not a palindrome \n",n);
    return 0;
}
