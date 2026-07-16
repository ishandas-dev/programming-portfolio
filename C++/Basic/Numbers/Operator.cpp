/*Program of using basic arithmetic operators using c++*/

#include<iostream>
using namespace std;
int main()
{
    //variables to store inputs and results of each operation
    float a,b,add=0.0,sub=0.0,mul=0.0,div=0.0;
    cout << "Enter the value of a and b\n";
    cin >> a >> b;

    //performing all four operations
    add=a+b;
    sub=a-b;
    mul=a*b;
    div=a/b;
    cout << "The sum of a and b is " << add << "\n"
         << "The difference of a and b is " << sub << "\n"
         << "The product of a and b is " << mul << "\n"
         << "The quotient of a and b is " << div << "\n";
        return 0;
}