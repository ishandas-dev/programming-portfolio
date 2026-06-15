//Learning type casting in C++

#include <iostream>
using namespace std;
int main()
{
    char grade = 'A', grade2 = 'a';
    int value = grade, value2 = grade2;

    cout << "The letter inside grade is " << grade <<"\n" << "and its value is " <<value <<"\n";
    cout << "The size of the grade variable is " << sizeof(grade) << " and the size of the value variable is " << sizeof(value) << "\n";
     
    cout << grade2 <<"\n" << value2 <<"\n";
    cout << sizeof(grade2) << "\n" << sizeof(value2) << "\n";
    
    return 0;
}