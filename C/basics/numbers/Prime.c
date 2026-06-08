/* To check the given number is prime or composite number using C (Prime numbers are natural numbers
 greater than 1 with exactly two factors (1 and themselves), 
 Example of prime numbers are: 2, 3, 5, and 7. 
 while Composite numbers are natural numbers greater than 1 with more than two factors
 Example of Composite numbers are: 4, 6, 8, and 9. 
The number 1 is considered neither prime nor composite.)*/

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
