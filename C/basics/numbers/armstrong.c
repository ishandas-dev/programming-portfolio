/* To check the given number is armstrong number or not using C*/
#include<stdio.h>
#include<math.h> //including this header file to use pow function
int main()
{
    int n,temp=0,digit=0,count=0;
    float sum=0.0;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    temp=n; //storing value in temporary variable

    //counting how many digits are present in the number
    while(temp>0)
    {
        count++; 
        temp=temp/10;
    }
    temp=n; //resetting temp to n for second loop

    //calculating sum of digits raised to the power pf digit count
    while(temp>0)
    {
        digit=temp%10;      // extracting the last digit of the number
        sum=sum+pow(digit,count);   //raising digit to power and adding to sum
        temp=temp/10;   //removing the last digit
    }
    if((int)sum==n)
    printf("The given number %d is armstrong number \n",n);
    else
    printf("The given number %d is not armstrong number \n",n);
}