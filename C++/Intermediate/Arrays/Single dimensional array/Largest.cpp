/*Write a program in C++ to find the largest number in an array.Take the size and elements of the array 
as input from the user, then traverse the array to find the maximum element*/

#include<iostream>
using namespace std;
int main()
{
    int n,i;
    int ch;
    cout << "Enter the size of the array \n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array \n";
    for(i=0;i<n;i++)
    {
        cin >> arr[i];//entering the elements in the array
    }
    cout << "To find the largest number in the array choose '1' \nor to find the smallest number in the array choose '2' \n";
    cin >> ch;
    switch(ch)
    {
    case 1:
    {
    int max = arr[0];  //assume first element is the largest to start
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
           max=arr[i];   //update max whenever a bigger element is found
        }
    }
    cout << "The largest number in the array is " << max << "\n";
    break;
    }
    case 2:
    {
        int min = arr[0];  //assume first element is the largest to start
        for(i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
           min=arr[i];   //update max whenever a bigger element is found
        }
    }
    cout << "The smallest number in the array is " << min << "\n";
    break;
    }
    default:
    {
        cout << "Wrong choice choose again \n";
    }
    return 0;
}
}