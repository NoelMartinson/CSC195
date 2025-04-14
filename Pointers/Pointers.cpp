#include <iostream>

void func1() {
	bool b = true;
	int i = 5;
}

void func2() {
	bool b = false;
	float f = 10;

	func1();
}

void func3() {
	int i[100000];

}

//class Animal {
//public:
//	Animal(std::string name) {
//		m_name = name;
//	}
//
//private:
//	std::string name() {
//
//	}
//};

void setValue(int* v) {
	*v = 5;

}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int i = 5;
	float f = 4.5f;

	//func2();
	//func3();
	/*{
		int* pointer = new int(5);
		std::cout << *pointer << std::endl;
		delete pointer;
	}
	Animal* dog = new Animal("Dog");
	std::cout << dog->getName() << std::endl;
	delete dog;
	dog = nullptr;
	if (dog) {
		std::cout << dog->getname() << std::endl;
	}

	std::cout << dog->getName() << std::endl;

	Animal cat("Cat");
	std::cout << cat->getName() << std::endl;*/

	int* block = (int*)malloc(sizeof(int) * 1000);
	block[0] = 3;
	block[1] = 4;
	block[2] = 5;
	block[3] = 6;

	block++;
	std::cout << (block + 2) << std::endl;
	free(--block);

	int v1 = 10;
	int v2 = 20;

	int* p = nullptr;
	std::cout << p << std::endl;
	p = &v1;
	*p = 5;
	std::cout << p << std::endl;
	std::cout << v1 << std::endl;

	p = &v2;
	*p = 15;

	std::cout << p << std::endl;
	std::cout << v2 << std::endl;

	//setValue(p);
	//std::cout << v2 << std::endl;

	std::cout << 1 << " " << v2 << std::endl;
	swap(&v1, &v2);
	std::cout << 1 << " " << v2 << std::endl;
}