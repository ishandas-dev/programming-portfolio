#include<stdio.h>
#include<math.h>
int main()
{
    int a=0,r=0,n=0,i;
    float sum=0.0;
    printf("Enter the total numbers \n");
    scanf("%d",&n);
    printf("Enter the first number of the series \n");
    scanf("%d",&a);
    printf("Enter the common ratio of the series \n");
    scanf("%d",&r);
    for(i=a;i<=a*pow(r,n-1);i=i*r)
    {
         printf("%d ",i);
    }
    sum= (a*(pow(r,n)-1.0))/(r-1.0);
    printf("\nThe sum of this geometric series is %f",sum);
    return 0;
}
