#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>

int main(){

	std::cout << sizeof(Human) << std::endl;
	std::cout << sizeof(Student) << std::endl;

	Student student1("Agone", 19, 3.3f);

	std::cout << student1.getName() << std::endl;
	std::cout << student1.getAge() << std::endl;
	
}