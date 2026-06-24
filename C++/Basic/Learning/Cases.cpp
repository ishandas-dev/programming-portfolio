
#include <iostream>
using namespace std;
int main ()
{
    char alphabet,alph;
    cout << "Enter the alphabet \n" ;
    cin >> alphabet;
    if ((int)alphabet >=65 && (int)alphabet <=90)
    {
        cout << "The given alphabet " << alphabet << " is in upper case \n";
        alph = (int)alphabet+32;
        cout << "Now the alphabet is " << alph << " is in lower case \n";
    }
    else
    {
        cout << "The given alphabet " << alphabet << " is in lower case \n";
        alph = (int)alphabet-32;
        cout << "Now the alphabet is " << alph << " is in upper case \n";
    }
    return 0;
}