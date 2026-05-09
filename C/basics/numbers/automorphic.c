#include<stdio.h>
int main()
{
    int n,temp=0,digit,check=1,i,square;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    temp=n;
    square=n*n;
    while(temp>0)
    {
        digit++
        temp=temp/10;
    }
    for(i=0;i<digit;i++)
    {
        check=check*10;
    }
    if(square%check==n)
    printf("The given number %d is an automorphic number \n",n);
    else
    printf("The given number %d is not an automorphic number \n",n);
}
