/*Write a C program to read 'n' integers into an array and:
  1.Print all the even numbers present in the array
  2.Print all the odd numbers present in the array
  3.Print the total count of even numbers and odd numbers in the array*/

#include<iostream>
using namespace std;
int main()
{
    int n,i,even=0,odd=0;
    cout << "Enter the size of the array \n";
    cin >> n;
    int arr[n];  //creating array of size n
    cout << "Enter the elements in the array \n";
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << "The even numbers present in the array are: ";
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0) //checking for even numbers
        {
            if(even!=0)   //checking if the current number is first even number or not
            cout << ", "; //adding commas before the number for the even series
            cout << arr[i]; //printing the even series
            even++;     //counting the even numbers
        }
    }   
    cout << "\nThe odd numbers present in the array are: ";
    for(i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
        {
            if(odd!=0)     //checking if the current number is first odd number or not
            cout << ", ";  //adding commas before the number for the odd series
            cout << arr[i]; //printing the odd series
            odd++;         //counting the odd numbers
        }
    }
    cout << "\nNumber of Even numbers in the array are " << even;
    cout << "\nNumber of Odd numnbers in the array are " << odd ;
    return 0;
}
