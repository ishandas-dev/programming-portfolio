/*Learning how to print statments , variables using different data types in c++*/

#include <iostream>
using namespace std;
int main()
{
    int age=19;
    char grade = 'A';
    float GC = 9.8f;
    double price = 100.55;
    bool check = true;
    bool check2 = false;
    
    cout << "Hello world \nMy name is Ishan Das \n";

    cout << "My age currently is " << age <<"\n";
    cout << "Size of age variable is which is in integer data type is " << sizeof(age) << "\n";

    cout << "Value of grade is " << grade <<"\n";
    cout << "Size of grade variable is  " << sizeof(grade) <<"\n";

    cout << "Value of gravitational constant which is in float data type is " << GC << "\n";
    cout <<"Size of GC variable is " << sizeof(GC) << "\n";

    cout << "Value of price variable which is in double data type is " << price << "\n";
    cout << "Size of price variable is " << sizeof(price) <<"\n";

    cout << "Check variable should return 1 if the value is true " << check << "\n";
    cout << "Size of check variable which is in boolean data type " << sizeof(check) << "\n";

    cout << "Check2 variable should return 0 if the value is false " << check2 << "\n";
    cout << "Size of check2 varible which is in boolean data type is " << sizeof(check2) << "\n";


    return 0;

}