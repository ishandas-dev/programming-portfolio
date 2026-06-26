/*Printing all the numbers using while loop till num in c++*/

#include <iostream>
using namespace std;
int main()
{
    int i=1,num;
    cout << "Enter the value till which you want to print \n";
    cin >> num;
    while(i<=num)
    {
        cout << i;
        if(i!=num)
        {
            cout << " , ";
        }
        i++;
    }
    return 0;
}