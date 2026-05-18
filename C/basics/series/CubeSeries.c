#include<stdio.h>
int main()
{
    int cube=0,n,i;
    printf("Enter the value of of number \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        cube=i*i*i;
        printf("%d ",cube);
        cube=0;
    }
    return 0;
}