/*An inverted right triangle pattern in programming is a geometric shape made of characters (like * or numbers) 
where the widest part is at the top, and the rows progressively decrease in size to form a point pointing downwards.*/

#include<stdio.h>
int main()
{
    int i,j,row=0;
    printf("Enter the number \n");
    scanf("%d",&row);

    //printing the pattern
    for(i=1;i<=row;i++)
    {
        for(j=row;j>=i;j--) //using loop from given row's value till the value of i variable, j decrement with every loop
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}