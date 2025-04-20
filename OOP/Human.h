#pragma once
#include <iostream>
using age_t = unsigned short;
class Human {
public:
	Human() {
		std::cout << "constructor\n";
	}
	Human(std::string name, age_t age) {
		name = name;
		age = age;

		std::cout << "constructor\n";
		count++;
	}

	~Human() {
		std::cout << "destructor\n";
		count--;
	}

	std::string getName() { return name; }
	unsigned short getAge() { return age; }
	void setAge(age_t age) { age = age; }

	static int getCount() { return count; }

private:
	std::string name;
	age_t age = 0;
	static int count;
	static const float tax;

};

void fnc() {}

