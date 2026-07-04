/*Take a number 'row' as input. Print a square pattern of size row x row where numbers are filled 
continuously from 1 to row*row , row by row from left to right.
 Example: row = 5
 1  2  3  4  5
 6  7  8  9  10
 11 12 13 14 15
 16 17 18 19 20
 21 22 23 24 25 */

#include<iostream>
using namespace std;
int main()
{
    int i,row=0,j,num=1;  // num starts at 1 and increments continuously across all rows
    cout << "Enter the number of rows \n";
    cin >> row;
    for(i=1;i<=row;i++)   //outer loop is used for the number of rows
    {
        for(j=1;j<=row;j++)  //inner loop prints row numbers and moves to next
        {
            cout << num << " ";  //printing the pattern 
            num++;  //num never resets, keeps going till row*row
        }
        cout << "\n";  //move to next row after printing all columns
    }
    return 0;
}