/*Checking the greatest number using C++*/

#include <iostream>
using namespace std;\
int main()
{
    int a,b;
    cout << "Enter the value of a and b respectively \n";
    cin >> a >> b;
    if(a>b)
    cout << "The greatest number is 'a' whose value is " << a << " While the smallest number is 'b' whose value is " << b;
    else
    cout << "The greatest number is 'b' whose value is " << b << " While the smallest number is 'a' whose value is " << a;
    return 0;
}