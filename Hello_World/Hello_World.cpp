#include "student.h"
#include <iostream>
#include <vector>
#include <list>
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

    vector<int> vec = { 1,2,3,4,5 };

    //Creates two ints at the end
    vec.push_back(6);
    vec.push_back(7);
    vec[0] = 5;

    //Removes the very last int
    vec.pop_back();

    //Shows the current size of the vector
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    string l = "\n List";
    cout << l << endl;
    //list

    list<string> lst = { "Apple", "Pear", "Grape" };

    //Creates an item at the front and back
    lst.push_front("Cherry");
    lst.push_back("Orange");

    list<int>::iterator iter = lst.begin();
    cout << *iter << endl;
    iter++;

    //Removws an item
    lst.remove("Pear");

    for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}

