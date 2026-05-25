/*Floyd's triangle is a right-angled triangular array of consecutive natural numbers. Named after 
computer scientist Robert W. Floyd, it is built by filling the rows with incremental numbers from 
left to right, where the first row has 1 element, the second has 2, and so on*/

#include<stdio.h>
int main()
{
    int row=0,i,j,k=1;
    printf("Enter the number of row \n");
    scanf("%d",&row);

    //using nested loop to print the Floyd triangle
    for(i=1;i<=row;i++)
    {
       for(j=1;j<=i;j++)
       {
            printf("%d ",k);
            k++;  //using k variable to keep the track on consecutive variable
       }
       printf("\n");
    }
    return 0;
}