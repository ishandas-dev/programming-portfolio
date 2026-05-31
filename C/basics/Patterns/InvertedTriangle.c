#include<stdio.h>
int main()
{
    int i,j,row=0;
    printf("Enter the number \n");
    scanf("%d",&row);
    for(i=1;i<=row;i++)
    {
        for(j=row;j>=i;j--)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}