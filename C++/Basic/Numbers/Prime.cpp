/* Take a number 'num' (greater than 1) as input. Check whether it is a prime number or a 
composite number by counting how many numbers between 1 and num divide it evenly. If exactly
 2 numbers divide it (1 and itself), it's prime; otherwise it's composite.
Example: num = 7  -> The given number is a prime number 7
Example: num = 10 -> The given number is a composite number 10*/

#include<iostream>
using namespace std;
int main()
{
    int i,num=0,count=0;
    cout << "Enter a number greater than 1 \n";
    cin >> num;

    // count how many numbers from 1 to num divide num evenly
    for(i=1;i<=num;i++)
    {
        if(num%i==0)
        count++;
    }
    if(count==2) // checking if the number is prime or not
    cout << "The given number is a prime number " << num << "\n";
    else 
    cout << "The given number is a composite number " << num << "\n";
    return 0;
}