/*An arithmetic series is the sum of the terms in an arithmetic sequence (a list of numbers where 
the difference between consecutive terms is always constant).
For example : the sequence 2, 5, 8, 11, 14 is an arithmetic sequence with a constant difference of 
3 . When you add them together 2 + 5 + 8 + 11 + 14 = 40 , it becomes an arithmetic series.*/

#include<iostream>
using namespace std;
int main()
{
    int a=0,d=0,num=0,i,r=0;
    float sum=0.0;
    cout << "Enter the total numbers \n";
    cin >> num;
    cout << "Enter the first number \n";
    cin >> a;
    cout << "Enter the difference between the numbers \n";
    cin >> d;
    r=a+(num-1)*d; //finding out the last term

    //using loop to print the arithmetic series
    for(i=a;i<=r;i=i+d) //loop from first term to last term, increment by common difference
    {
        cout << i;
        if(i<r)
        {
            cout << ","; //adding comma after every digit till the last num
        }
    }
    sum = (num/2.0)*(2.0*a+(num-1)*d); //calculating the sum of arithmetic series by using its formula
    cout << "\nThe sum of this arithmetic series is " << sum;
    return 0;
} 