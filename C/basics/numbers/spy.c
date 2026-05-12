/*To check the given number is spy number or not in C (A Spy number is a positive integer where the
sum of its digits equals the product of its digits.)
Example of spy number are: 1124 as 1+1+2+4=8 and 1*1*2*4=8*/

#include<stdio.h>
int main()
{
    int sum=0,pro=1,digit=0,temp=0,n;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    temp=n; //using the temporary variable to store the number

    //calculating the sum and product of digits present in the number
    while(temp>0)
    {
        digit=temp%10; //extracting the last digit of the number
        sum=sum+digit; //storing the sum of all digits
        pro=pro*digit; //storing the product of all digits
        temp=temp/10;  //removing the last digit
    }
    if(sum==pro)
    printf("The given number %d is a spy number as its sum %d and its product %d is same",n,sum,pro);
    else
    printf("The given number %d is not a spy number as its sum %d and its product %d is different",n,sum,pro);
    return 0;
}