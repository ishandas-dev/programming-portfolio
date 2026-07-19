/*Write a program to read an integer and print it's multiplication table*/

#include<stdio.h>
int main()
{
    int num=0,i,mul=1;
    printf("Enter the number to be multipled \n");
    scanf("%d",&num);
    printf("The multiplication table of the given number %d \n",num);
    
    //using loop to print multiplication table
    for(i=0;i<=num;i++)  
    {
        mul=i*num; 
        printf("%d*%d=%d\n",i,num,mul);
    }
    return 0;
}