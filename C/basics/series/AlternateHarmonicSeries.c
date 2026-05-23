/*The alternating harmonic number is the partial sum of the alternating harmonic series. It represents
the sum of the reciprocals of the first n natural numbers, with alternating positive and negative
signs like (1 - 1/2 + 1/3 - 1/4 till 1/n).*/

#include<stdio.h>
int main()
{
    int i,n;
    float total=0.0;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
        total=total-(1.0/i);
        else
        total=total+(1.0/i);
    }
    printf("The sum of Alternate harmonic series for given number %d is %f",n,total);
    return 0;
}
    