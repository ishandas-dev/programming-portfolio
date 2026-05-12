/*To check the given number is strong number or not in C (A Strong number is a special number in 
mathematics and computer science where the sum of the factorials of its digit equals the original number
Example of strong number are: 145 as 1!+4!+5! = 145 itself )*/


#include<stdio.h>
int main()
{
    int n,fact=1,i,temp=0,digit=0,sum=0;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    temp=n; //using a temporary variable for storing our given value

    //finding out the sum of the factorials of its digits 
    while(temp>0)
    {
        digit=temp%10; //extracting the last digit of the number
        for(i=1;i<=digit;i++)
        {
            fact=fact*i;//Storing the factorial of the digit
        }
        sum=sum+fact; //storing the sum of all the digits factorial
        fact=1;       //initializing fact as 1 so we can use it again for another digit
        temp=temp/10; //removing the last digit
    }
    if(n==sum)
    printf("The given number %d is a strong number as it's sum of its digit's factorial is also %d \n",n,sum);
    else
    printf("The given number %d is not a strong number as it's sum of its digit's factorial is %d \n",n,sum);
}