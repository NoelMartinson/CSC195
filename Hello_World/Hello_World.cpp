#include "student.h"
#include <iostream>
using namespace std;

class Person {
public:
    float weight;
    int age;

    void f() {}
};

int main() {
    Student student;
    student.SetName("Isaac");
    student.Write();

    cout << "Hello, World!" << endl;
    cout << "Git is now tracking this project!" << endl;

    unsigned int i = 82;

    std::cout << i << std::endl;
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(Person) << std::endl;
   
    cout << i++ << endl;

    char c = 'A';
    cout << &i << endl;

    f();
    Student student;
    return 0;
}

