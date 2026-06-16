//Learning type casting in C++

#include <iostream>
using namespace std;
int main()
{
    char grade = 'A', grade2 = 'a';
    int value = grade, value2 = grade2;

    cout << "The letter inside grade variable is " << grade << " and its value in integer is " <<value <<"\n";
    cout << "The size of the grade variable is " << sizeof(grade) << "cand the size of the value variable is " << sizeof(value) << "\n";
     
    cout <<"The letter inside grade2 variable is " << grade2 << " and its value in integer is " << value2 <<"\n";
    cout <<"The size of the grade2 variable is " << sizeof(grade2) << " and the size of the value variable is " << sizeof(value2) << "\n";
    
    return 0;
}