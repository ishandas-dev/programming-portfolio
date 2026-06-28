/*Take a number 'n' as input. Print a square pattern of '*' 
   with n rows and n columns.
   Example: n = 4
   * * * *
   * * * *
   * * * *
   * * * * */

#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter the size of the square: ";
    cin >> num;
    for (int i = 1; i<=num; i++) // outer loop runs for each row
    {
        for (int j = 1; j<=num; j++)  // inner loop prints n stars in that row
        {
            cout << "* ";
        }
        cout << "\n"; // move to next row
    }
    return 0;
}