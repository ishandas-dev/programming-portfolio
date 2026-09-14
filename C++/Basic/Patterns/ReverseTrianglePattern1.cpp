/*Take a number 'row' as input. Print an inverted triangle pattern where each row prints numbers 
counting down from the row number to 1.
 Example: row = 4
   1
   2 1
   3 2 1
   4 3 2 1 */

#include<iostream>
using namespace std;
int main()
{
    int i,j,row=0;
    cout << "Enter the number of rows\n";
    cin >> row;
    for(i=1;i<=row;i++)  //outer loop runs for each row
    {
        for(j=i;j>=1;j--)  // inner loop counts down from i to 1
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}