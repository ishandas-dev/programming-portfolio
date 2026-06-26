/*Program to check whether an entered alphabet is uppercase or lowercase and convert it to the 
opposite case using ASCII value manipulation.Uppercase letters range from 65-90 and lowercase 
from 97-122 in ASCII,with a fixed difference of 32 between the same letter in both cases.
Example: Input 'A' (65) -> Output 'a' (97)
         Input 'b' (98) -> Output 'B' (66)*/

#include <iostream>
using namespace std;
int main ()
{
    char alphabet,alph;
    cout << "Enter the alphabet \n" ;
    cin >> alphabet;
    if ((int)alphabet >=65 && (int)alphabet <=90)  //check if entered character lies in uppercase ASCII range
    {
        cout << "The given alphabet " << alphabet << " is in upper case \n";
        alph = (int)alphabet+32;  //add 32 to ASCII value to shift uppercase to lowercase
        cout << "Now the alphabet is " << alph << " is in lower case \n";
    }
    else
    {
        cout << "The given alphabet " << alphabet << " is in lower case \n";
        alph = (int)alphabet-32;  // subtract 32 from ASCII value to shift lowercase to uppercase
        cout << "Now the alphabet is " << alph << " is in upper case \n";
    } 
    return 0;
}