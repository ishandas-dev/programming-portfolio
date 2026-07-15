/*To check the given number is Neon number or not using C++ (A neon number is a special integer where 
the sum of the digits of its square equals the original number.)
Example of neon number is: 9 as 9^2 = 81 and 8+1=9.*/

#include<iostream>
using namespace std;
int main()
{
    int num,square,temp=0,digit=0,sum=0;
    cout << "Enter the value of number\n";
    cin >> num ;
    square=num*num;
    temp=square; //using temporary variable to store the square of the given number

    //storing the sum of the digits of the square of given number
    while(temp>0)
    {
        digit=temp%10;
        sum=sum+digit;
        temp=temp/10;
    }
    if(sum==num)
    cout << "The given number " << num << " is a neon number as it's square is " << square << " whose digit's sum is " << sum << " itself ";
    else
    cout << "The given number " << num << " is not a neon number as it's square is " << square << " whose digit's sum is " << sum << " different ";
    return 0;
}