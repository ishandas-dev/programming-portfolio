/* Take a number 'num' as input. Print the series of all even numbers and all odd numbers from 
   1 to num separately (comma-separated, no trailing comma after the last number in each series). 
   Also calculate and print the sum of all even numbers and the sum of all odd numbers.(using for loop)
   Example: num = 7
   The even series is : 2 , 4 , 6
   The odd series is : 1 , 3 , 5 , 7
   Sum of all even numbers is 12
   Sum of all odd numbers is 16*/

#include <iostream>
using namespace std;
int main()
{
    int i,num=0,even_sum=0,odd_sum=0;
    int last_even=0,last_odd=0; // store the last even and last odd number up to num
    cout << "Enter the number till which numbers are needed \n";
    cin >> num;
     if(num%2==0)
     {
        last_even=num;  // num itself is the last even number
        last_odd=num-1; // one less than num is the last odd number
     }
     else
     {
        last_even=num-1; // one less than num is the last even number
        last_odd=num;    // num itself is the last odd number
     }
    cout << "The even series is : ";
    for(i=1;i<=num;i++)
    {
        if(i%2==0) // check if i is even
        {
            cout << i ;
            if (i!=last_even)  // print comma only if not the last even number
            {
                cout << " , ";
            }
            even_sum = even_sum + i; // add current even number to the running sum
        }
    }
    cout << "\n" << "The odd series is : ";
    for(i=1;i<=num;i++)
    {
        if(i%2!=0)
        {
            cout << i ;
            if (i!=last_odd) // check if i is odd
            {
                cout << " , ";  // print comma only if not the last odd number
            }
            odd_sum = odd_sum + i; // add current odd number to the running sum
        }
    }
    cout << "\nSum of all even numbers is " << even_sum;
    cout << "\nSum of all odd numbers is " << odd_sum ;
    return 0;
}