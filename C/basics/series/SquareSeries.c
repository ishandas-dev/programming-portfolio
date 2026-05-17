/*A square number series is a mathematical sequence where each term is the product of an 
integer multiplied by itself, expressed as \(n^{2}\).
 The sequence begins (1, 4, 9, 16, 25, 36, 49, 64, 81, 100 till n)*/

#include<stdio.h>
int main()
{
    int n,i,square=0;
    printf("Enter the value till which the series to be printed\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        square= i*i; //squaring the number
        printf("%d ",square);
        square=0;//again initializing the variable to 0 so we can use it again
    }
    return 0;
}