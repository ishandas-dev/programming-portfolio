/*In mathematics and reasoning tests, a cube series (or cubic sequence) is a sequence of numbers
 in which each term is found by taking the cube of its position in the series. 
 This means a number is multiplied by itself, and then by itself again (n*n*n or n^3)
 The sequence begins (1,8 27 64 125 216 343 512 729 1000 till n )*/

#include<stdio.h>
int main()
{
    int cube=0,n,i;
    printf("Enter the value of of number \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        cube=i*i*i;//cubing the number
        printf("%d ",cube);
        cube=0;//again initializing the variable to 0 so we can use it again
    }
    return 0;
}