/*The harmonic series is a mathematical sequence defined as the sum of reciprocals: 
(1+ 1/2 + 1/3 +1/n). In computing, it is most famous for its
 paradoxical behavior with floating-point math: despite the individual terms becoming infinitely 
 small, the total sum keeps growing forever, eventually overflowing your system"s memory limit */

#include<stdio.h>
int main()
{
    int i,n,a=1;
    float sum=0.0;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("%d/%d",a,i);
        if(i<n)
        {
            printf(" + ");
        }
        sum=sum+(1.0/i); //using loop variable i which will change its value in every loop
    }
     printf("\nThe sum of this harmonic series is %f \n",sum);
     return 0;
}