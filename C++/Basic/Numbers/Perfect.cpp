/*To check the given number is perfect number or not using C++ (A perfect number is a positive integer
 equal to the sum of its proper positive divisors (excluding the number itself))
Example of perfect number are : 6 (divisors: 1, 2, 3 and 1+2+3=6) 
                                28 (divisors: 1, 2, 4, 7, 14 and 1+2+4+7+14=28)  */
 
#include<iostream>
using namespace std;
int main()
{
    int num=0,i,sum=0;
    cout << "Enter the value of number \n";
    cin >> num;

    //to store the sum of all the numbers which are divisble to the given number
    for(i=1;i<num;i++)
    {
        if(num%i==0)
        sum=sum+i;
    }
    if(sum==num)
    cout <<"The given Number " << num << " is perfect number \n";
    else
    cout << "The given Number " << num << " is not a perfect number \n";
    return 0;
}