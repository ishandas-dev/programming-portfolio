/* To check the given number is palindrome number or not using C (A palindromic number is a number
 that remains the same when its digits are reversed, reading the same forwards and backwards.)
 Example of palindrome number are: 121,3443 */

#include<stdio.h>
int main()
{
    int n,digit=0,rev=0,temp=0;
    printf("Enter the number \n");
    scanf("%d",&n);
    temp=n; //using temporary variable to save the original number 
    while(temp>0)
    {
        digit=temp%10; //extracting the last digit of the number
        rev=(rev*10)+digit; //reversing the number
        temp=temp/10; //removing the last digit
    }
    if (n==rev)
    printf("the given number %d is a palindrome \n",n);
    else
    printf("the given number %d is not a palindrome \n",n);
    return 0;
}
