/* To check the given number is even or odd using C 
(Even numbers are integers exactly divisible by 2 (ending in 0, 2, 4, 6, or 8), 
while odd numbers are integers not divisible by 2 (ending in 1, 3, 5, 7, or 9)*/

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    if(n%2==0) //checking if the number is divisible by 2 or not
    printf("The given number %d is even \n",n);
    else
    printf("The given number %d is odd \n",n);
    return 0;
}