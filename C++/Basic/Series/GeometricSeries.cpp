/*A geometric series is the sum of the terms in a geometric sequence (a list of numbers where 
each term is multiplied by a fixed common ratio).
For example : the sequence 2, 6, 18, 54, 162 is a geometric sequence with a common ratio of 
3 . When you add them together 2 + 6 + 18 + 54 + 162 = 242 , it becomes a geometric series.*/

#include<iostream>
using namespace std;
#include<cmath> //including this header file to use pow function
int main()
{
    int a=0,r=0,n=0,i;
    float sum=0.0;
    cout << "Enter the total numbers \n";
    cin >> n;
    cout << "Enter the first number of the series \n";
    cin >> a;
    cout << "Enter the common ratio of the series \n";
    cin >> r;

    //using loop to print the Geometric series
    for(i=a;i<=a*pow(r,n-1);i=i*r) //loop from first term to last term, increment by multiplying the common ratio
    {
        cout << i;
        if(i*r <= a*pow(r,n-1))   //if there's a next term coming, print comma
        {
        cout << ",";
        }
    }
    sum= (a*(pow(r,n)-1.0))/(r-1.0); //calculating the sum of Geometric series by using its formula
    cout << "\nThe sum of this geometric series is " << sum; 
    return 0;
}
