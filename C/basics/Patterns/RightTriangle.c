/*A right triangle pattern (commonly built using asterisks or numbers) is a popular programming
 exercise where the number of symbols in each row increases progressively. A standard right-aligned 
 or left-aligned triangle represents a 90 right angle configuration*/

#include<stdio.h>
int main()
{
    int row=0,col=0,i,j;
    printf("Enter the row \n");
    scanf("%d",&row);

    //printing the right triangle pattern
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=i;j++) //using loop from 1 till the value of i variable
        {
            printf("* "); //printing asterisks 
        }
        printf("\n");
    }
    return 0;
}