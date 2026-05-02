/*Program of using basic arithmetic operators using c*/
#include<stdio.h>
int main()
{
    //variables to store inputs and results of each operation
    float a,b,add=0.0,sub=0.0,mul=0.0,div=0.0;
    printf("Enter the value of a and b \n");
    scanf("%f%f",&a,&b);
    //performing all four operations
    add=a+b;
    sub=a-b;
    mul=a*b;
    div=a/b;
    printf("The sum of a and b is %f \n"
        "The difference of a and b is %f \n"
        "The product of a and b is %f \n"
        "The quotient of a and b is %f \n ",add,sub,mul,div);
        return 0;
}