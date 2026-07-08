#include<iostream>
using namespace std;
int main()
{
    int i,j,row=0;
    cout << "Enter the number of rows\n";
    cin >> row;
    for(i=1;i<=row;i++)
    {
        for(j=i;j>=1;j--)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}