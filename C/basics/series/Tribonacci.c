/*Floyd's triangle is a right-angled triangular array of consecutive natural numbers. Named after 
computer scientist Robert W. Floyd, it is built by filling the rows with incremental numbers from
 left to right, where the first row has 1 element, the second has 2, and so on.
 the series looks like : The series typically starts with the initial values (0,0,1,1,2,4,7,13,24,44,81,149,274 till n)*/

#include<stdio.h>
int main()
{
    int a=0,b=0,c=1,d=0,i,n=0;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    //using loop tp print the Tribonacci series
    for(i=1;i<=n;i++)
    {
        printf("%d ",a); // print current term
        d=a+b+c;      // calculate next term (sum of previous 3)
        a=b;          // shift a to next position
        b=c;        // shift b to next position
        c=d;        // shift c to next position
    }
    return 0;
}