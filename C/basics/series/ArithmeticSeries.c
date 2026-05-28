/*An arithmetic series is the sum of the terms in an arithmetic sequence (a list of numbers where 
the difference between consecutive terms is always constant).
For example : the sequence 2, 5, 8, 11, 14 is an arithmetic sequence with a constant difference of 
3 . When you add them together 2 + 5 + 8 + 11 + 14 = 40 , it becomes an arithmetic series.*/

#include<stdio.h>
int main()
{
    int a=0,d=0,n=0,i;
    float sum=0.0;
    printf("Enter the total numbers \n");
    scanf("%d",&n);
    printf("Enter the first number \n");
    scanf("%d",&a);
    printf("Enter the difference between the numbers \n");
    scanf("%d",&d);

    //using loop to print the arithmetic series
    for(i=a;i<=a+(n-1)*d;i=i+d) //loop from first term to last term, increment by common difference
    {
        printf("%d ",i);
    }
    sum = (n/2.0)*(2.0*a+(n-1)*d); //calculating the sum of arithmetic series by using its formula
    printf("\nThe sum of this arithmetic series is %f",sum);
    return 0;
} 