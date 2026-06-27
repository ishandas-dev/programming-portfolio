 /* This program prints a right-angled triangle pattern of stars.
       Example: for n = 4, output is:
       *
       * *
       * * *
       * * * * */

#include <iostream>
using namespace std;
int main() 
{
    int n;
    cout << "Enter number of rows: \n";
    cin >> n; 
    for (int i = 1; i <= n; i++) // outer loop controls the rows
    {
        for (int j = 1; j <= i; j++) // inner loop prints stars for current row
        {
            cout << "* ";
        }
        cout << endl; // move to next line after each row
    }
    return 0;
}