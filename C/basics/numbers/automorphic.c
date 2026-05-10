/*To check the given number is automorphic number or not using C*/
#include<stdio.h>
int main()
{
    int n,temp=0,digit=0,check=1,i,square;
    printf("Enter the value of number \n");
    scanf("%d",&n);
    temp=n; //using temporary variable to store the given number
    square=n*n;

    //counting how many digits are there in the number
    while(temp>0)
    {
        digit++;
        temp=temp/10;
    }

    /*To get 10^digits so that we can extract the required data 
    from square to check automorphic number*/
    for(i=0;i<digit;i++)
    {
        check=check*10;
    }
    if(square%check==n)
    printf("The given number %d is an automorphic number as it's square is %d\n",n,square);
    else
    printf("The given number %d is not an automorphic number as it's square is %d\n",n,square);
}
