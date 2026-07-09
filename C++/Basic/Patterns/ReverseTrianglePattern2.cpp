/*Take a number 'row' as input. Print a pattern where each row has increasing leading spaces from 
the left and decreasing repetitions of the row number, with no spaces between the numbers.
 Example: row = 4
   1111
    222
     33
      4 */

#include<iostream>
using namespace std;
int main()
{
    int i,j,row=0;
    cout << "Enter the number of rows\n";
    cin >> row;
    for(i=1;i<=row;i++)  //outer loop runs for each row
    {
        for(j=1;j<i;j++)  //print leading spaces increases by 1 each row
        {
            cout << " ";
        }
        for(j=1;j<=row-i+1;j++)  //print row number (row - i + 1) times decreases each row
        {
            cout << i ;   //no space here, numbers stay together
        }
        cout << "\n";
    }
    return 0;
}