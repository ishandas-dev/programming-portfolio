/*A geometric series is the sum of the terms in a geometric sequence (a list of numbers where 
each term is multiplied by a fixed common ratio).
For example : the sequence 2, 6, 18, 54, 162 is a geometric sequence with a common ratio of 
3 . When you add them together 2 + 6 + 18 + 54 + 162 = 242 , it becomes a geometric series.*/

#include<stdio.h>
#include<math.h> //including this header file to use pow function
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

    //using loop to print the Geometric series
    for(i=a;i<=a*pow(r,n-1);i=i*r) //loop from first term to last term, increment by multiplying the common ratio
    {
         printf("%d ",i); 
    }
    sum= (a*(pow(r,n)-1.0))/(r-1.0); //calculating the sum of Geometric series by using its formula
    printf("\nThe sum of this geometric series is %f",sum); 
    return 0;
}
