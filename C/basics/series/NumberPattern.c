/*To write a program in c to print triangular number pattern or a sequential number pyramid like as shown below
example : if the number of rows is entered 5 by the user then output should be :
1
12
123
1234
12345*/

#include<stdio.h>
int main()
{
    int row,j,i;
    printf("Enter the number of row \n");
    scanf("%d",&row);
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=i;j++)
        {
        printf("%d",j);
    }
    printf("\n");
}
    return 0;
}