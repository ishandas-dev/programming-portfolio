/*Take a number 'row' as input. Print a triangle pattern where each row prints numbers 
starting from 1 up to the current row number.
Example: row = 4
   1
   1 2
   1 2 3
   1 2 3 4 */

#include <iostream>
using namespace std;
int main()
{
    int i,j,row=0;
    cout << "Enter the number of rows \n"; 
    cin >> row;
    for(i=1;i<=row;i++)  //outer loop runs for each row
    {
        for(j=1;j<=i;j++)  //inner loop prints 1 to i in each row
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}