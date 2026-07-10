/*Write a program to print a pattern using alphabets, where each row contains letters continuing 
sequentially from where the previous row left off (not reset to 'A' each time).
Example (rows = 4):
A
B C
D E F
G H I J */

#include <iostream>
using namespace std;
int main()
{
    int i,row=0,j;
    char letter='A';  //starting alphabet 
    cout << "Enter the number of rows\n";
    cin >> row;
    if(row>26||row<1)
    {
        cout << "Invalid input!! please enter between 1 to 26\n";
        return 0;
    }
    for(i=1;i<=row;i++)    //outer loop controls the row number
    {
        for(j=1;j<=i;j++)  //inner loop prints 'i' letters, continuing the sequence
        {
            cout << letter << " ";
            letter=(int)letter+1;  //move to the next alphabet in sequence
        }
        cout << "\n";   //move to next line after each row=
    }
}