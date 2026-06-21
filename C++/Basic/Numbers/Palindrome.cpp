/* To check the given number is palindrome number or not using C (A palindromic number is a number
 that remains the same when its digits are reversed, reading the same forwards and backwards.)
 Example of palindrome number are: 121,3443 */

#include <iostream>
using namespace std;
int main()
{
    int digit=0,rev=0,temp,num=0;
    cout << "Enter the value of the number \n";
    cin >> num;
    temp=num; //using temporary variable to save the original number 

     //using the loop to reverse the given number
    while (temp>0)
    {
        digit=temp%10; //extracting the last digit of the number
        rev=(rev*10)+digit; //reversing the number
        temp=temp/10; //removing the last digit
    }
    if(rev==num)
    cout << "The given number " << num << " is a palindrome number";
    else
    cout << "The given number " << num << " is not a palindrome number";
}