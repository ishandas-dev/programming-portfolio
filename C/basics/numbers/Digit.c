/*Write a program to enter three digit number and print it's hundreth place in c*/

#include<stdio.h>
int main()
{
    int num=0,hun_digit=0; 
    printf("Enter the number \n");
    scanf("%d",&num);
    hun_digit=(num/100)%10;  //Extracting the hundredth digits
    printf("The hundred digit of the given number is %d \n",hun_digit);
    return 0;
}