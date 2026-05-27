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

    
    for(i=a;i<=a+(n-1)*d;i=i+d)
    {
        printf("%d ",i);
    }
    sum = (n/2.0)*(2.0*a+(n-1)*d);
    printf(" The sum of these series is %f",sum);
    return 0;
} 