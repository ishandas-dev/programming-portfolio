#include<stdio.h>
int main()
{
    int a=0,d=0,n=0,i;
    printf("Enter the total numbers \n");
    scanf("%d",&n);
    printf("Enter the first number \n");
    scanf("%d",&a);
    printf("Enter the difference between the numbers \n");
    scanf("%d",&d);
    for(i=a;i<=n*d;i=i+d)
    {
        printf("%d ",i);
    }
    return 0;
} 