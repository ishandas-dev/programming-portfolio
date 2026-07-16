/*To check the given number is automorphic number or not using C++(An automorphic number (or circular number) 
is a natural number whose square ends in the same digits as the number itself.
Example of Automorphic number are : 5^2 = 25 (Here 5 is the last digit in 25)
                                    76^2= 5776 (Here 76 is the last digit in 5776 )*/

#include<iostream>
using namespace std;
int main()
{
    int num,temp=0,digit=0,check=1,i,square;
    cout << "Enter the value of number\n";
    cin >> num;
    temp=num; //using temporary variable to store the given number
    square=num*num;

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
    if(square%check==num)
    cout << "The given number " << num << " is an automorphic number as it's square is " << square << "\n";
    else
    cout << "The given number " << num << " is not an automorphic number as it's square is " << square << "\n";
    return 0;
}
