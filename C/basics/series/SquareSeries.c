/*A square number series is a mathematical sequence where each term is the product of an 
integer multiplied by itself, expressed as (n^2).
 The sequence begins (1, 4, 9, 16, 25, 36, 49, 64, 81, 100 till n)*/

#include<stdio.h>
int main()
{
    int n,i,square=0;
    printf("Enter the value till which the series to be printed\n");
    scanf("%d",&n);

    //using loop for squaring the numbers
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            square=i*i; //squaring the starting number
            printf("%d",square); //printing the square
            square=0; //initializing the variable to 0 so we can use it again
        }
        else
        {
        square= i*i; //squaring the numbers
        printf(" , %d",square); //printing the square
        square=0; //again initializing the variable to 0 so we can use it again
        }
    }
    return 0;
}
//you might wonder why i am squaring 1 separately , its because i want to print "," too after each number