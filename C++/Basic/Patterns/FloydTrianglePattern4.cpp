/*Take a number 'row' as input. Print Floyd's Triangle, where natural numbers are filled continuously 
from 1, row by row, with eachrow containing one more number than the previous row.
Example: row = 4
   1
   2 3
   4 5 6
   7 8 9 10 */

#include <iostream>
using namespace std;
int main()
{
    int i,j,row=0,num=1;  //num increments continuously across all rows
    cout << "Enter the value of row \n";
    cin >> row;
    for(i=1;i<=row;i++)  //outer loop runs for each row
    {
        for(j=1;j<=i;j++)  //inner loop prints i numbers per row, continuing from last num
        {
            cout << num << " "; 
            num++;  //never resets, keeps going till row*(row+1)/2
        }
        cout << "\n";
    }
    return 0;
}
