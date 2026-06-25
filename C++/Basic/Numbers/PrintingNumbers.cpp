/*Printing all the numbers till num in c++*/

#include<iostream>
using namespace std;
int main()
{
    int i,num;
    cout << "Enter the value of number \n";
    cin >> num;
    cout << "Printng the numbers till num digits \n";

    //using loop to print the number till num
    for(i=1;i<=num;i++)
    {
        cout << i ; //printing the number
        if(i!=num)  //checking if i is not equal to num
        {
        cout << " , "; //giving comma after every digit
        }
    }
    return 0;
}