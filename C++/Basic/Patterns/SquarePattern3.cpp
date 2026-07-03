/*Take a number 'row' as input. Print a square pattern of sizerow x row where each row contains 
alphabets starting from 'A', resetting back to 'A' at the beginning of every new row.
Example: row = 5
A B C D E
A B C D E
A B C D E
A B C D E
A B C D E */

#include <iostream>
using namespace std;
int main()
{
    int i,row=0,j;
    char letter='A';  //starting alphabet for each row
    cout << "Enter the number of rows\n";
    cin >> row;
    if(row>26||row<1)
    {
        cout << "Invalid input!! please enter between 1 to 26\n";
        return 0;
    }
    for(i=1;i<=row;i++)  //outer loop controls the number of rows
    {
        for(j=1;j<=row;j++)  //inner loop prints alphabets A to (A + row - 1) in each row
        {
            cout << letter << " ";
            letter=1+(int)letter;  //move to the next alphabet using ASCII value
        }
        letter='A';  //reset back to 'A' for the next row
        cout << "\n";
    }
    return 0;
}
