 /*The Fibonacci series is a sequence where each number is the sum of the two preceding ones, usually 
 starting from 0 and 1. It follows the formula \(F(n) = F(n-1) + F(n-2)\), producing the sequence
 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ... n and appears frequently in nature.*/

 #include<stdio.h>
 int main()
 {
    int a=0,b=1,c=0,i,n;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    printf("The fibonacci is \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a); //printing the value of a in the beginning of the loop
        c=a+b;//adding the value of a and b varible respectively in c
        a=b;  
        b=c;     
    }
    return 0;
 }