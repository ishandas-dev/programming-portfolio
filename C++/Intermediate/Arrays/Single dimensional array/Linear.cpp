/*Write a C++ program to perform a Linear Search on an array and display the position where the number
is present*/

#include<iostream>
using namespace std;
int main()
{
    int n,i,key=0,count=0,pos=0;
    cout<<"Enter the size of the array \n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array \n";
    for(i=0;i<n;i++)
    {
        cin>> arr[i];
    }
    cout<<"Enter the element to be searched\n";
    cin>>key; //element for search
    for(i=0;i<n;i++)
    {
        pos++;       //finding the position in the array
        if(key==arr[i]) //checking if the element is present in the array or not
        {
        count++;
        break;
        }
    }
    if(count==1)
    cout<<"Yes the element is present in the array in the position "<<pos<<"\n";
    else
    cout<<"No the element is not present in the array\n";
    return 0;
}