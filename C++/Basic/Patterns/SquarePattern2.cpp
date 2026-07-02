/* Take a number 'row' as input. Print a square pattern of size row x row where each row contains numbers from 1 to row.
 Example: row = 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5 */

#include<iostream>
using namespace std;
int main()
{
    int i,row=0,j;
    cout << "Enter the number of row \n";
    cin >> row;
    for(i=1;i<=row;i++)  //outer loop controls the number of rows
    {
        for(j=1;j<=row;j++)  //inner loop prints numbers 1 to row in each row
        {
        cout << j;
        }
        cout << "\n"; //move to next row after printing all columns
    }
    return 0;
}