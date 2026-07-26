/*An alternating series is an infinite series where the signs of the terms continually flip back and
forth between positive and negative like sum of (1-2+3-4+5-6...till n)*/

#include<iostream>
using namespace std;
int main()
{
    int n,i,sum=0;
    cout << "Enter the value of n \n";
    cin >> n;
    cout << "The series looks like this :";
    for(i=1;i<=n;i++)
    {
        if(i==1) 
        {
        cout << i; //printing the first number of the series
        sum=sum+i;
        }
        else if(i%2==0) //checking for even and odd
        {
        cout << " - " << i ; //printing the series
        sum=sum-i; //calculating the sum
        }
        else
        {
        cout << " + " << i; //printing the series
        sum=sum+i; //calculating the sum
        }
    }
    cout << "\nThe sum of Alternate series for given number is: " << sum;
    return 0;
}

