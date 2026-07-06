/*Take a number 'row' as input. Print a triangle pattern where each row number is printed as many 
times as the row number itself.
Example: row = 4
1
22
333
4444 */

#include <iostream>
using namespace std;
int main()
{
    int i,j,row=0,num=1;  //num tracks the current row number to print
    cout << "Enter the number of rows \n";  
    cin >> row;
    for(i=1;i<=row;i++)  //outer loop runs for each row
    {
        for(j=1;j<=i;j++)  //inner loop prints num exactly i times in row i
        {
            cout << num << " ";
        }
        num++;   //move to next number after finishing current row
        cout << "\n";
    }
    return 0;
}