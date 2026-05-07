/* To check the given number is prime or composite number using C*/*/
#include<stdio.h>
int main()
{
    int n,i,count=0;   
    printf("Enter the value of number \n");
    scanf("%d",&n);
    //counting that from how many digits the number is divisible
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        count++;
    }
    if(count==2)
    printf("the given number %d is prime \n",n);
    else if(count!=2)
    printf("the given number %d is composite number \n",n);
    else
    printf("The given number is 1 which is neither prime nor composite \n");
    return 0;
}
