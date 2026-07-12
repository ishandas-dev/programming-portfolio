/*Write a program to print an inverted triangle pattern based on user input for number of rows, 
where each row contains the row number repeated a decreasing number of times, with increasing left padding.
Example for row = 4:
1111
 222
  33
   4*/

#include<iostream>
using namespace std;
int main()
{
    int i, j, row = 0;
    cout << "Enter the number of rows\n";
    cin >> row;

    for (i = 1; i <= row;i++)
    {
        for (j = 1; j < i; j++) // i-1 leading spaces
        {
            cout << " ";
        }
        for (j = 1; j <= row - i + 1; j++) // number i, repeated (row-i+1) times
        {
            cout << i ;
        }
        cout << "\n";
    }
    return 0;
}
