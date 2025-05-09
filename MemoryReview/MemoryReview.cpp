#include <iostream>
using namespace std;
struct Person
{
	char name[32];
	int id;
};

void square(int i) {
	i = i * i;
	std::cout << i << std::endl;
}

void dlouble(int* i) {
	*i = *i * 2;
	std::cout << *i << std::endl;
}

int main() {
	// ** REFERENCE **
	//
	int var = 7;
	int& ref = var;

	square(var);
	std::cout << var << std::endl;

	std::cout << var << std::endl;
	ref = 4;
	std::cout << var << std::endl;

	square(ref);
	std::cout << ref << std::endl;
	// what happened to the int variable when the reference was changed? (var took on ref's reference, and changed to what ref is)
	std::cout << &var << std::endl;
	std::cout << &ref << std::endl;
	// are the addresses the same or different? (same address: 000000C98058F924)
	// ** REFERENCE PARAMETER **
	
	// ** POINTER VARIABLE **
	int* pointer = nullptr;
	pointer = &var;
	std::cout << pointer << std::endl;
	// what is this address that the pointer is pointing to? (the same address as before: 000000C98058F924)
	std::cout << *pointer << endl;

	dlouble(pointer);
	
	
	// ** POINTER PARAMETER **
	std::cout << *pointer << std::endl;
	std::cout << var << std::endl;
	// did the int variable's value change when using the pointer? (it did, yes);
	return 0;
}

// ** REFERENCE **
//
// declare an int variable and set the value to some number (less than 10)
// declare a int reference and set it to the int variable above
// output the int variable
// set the int reference to some number
// output the int variable
// what happened to the int variable when the reference was changed? (insert answer)
// output the address of the int variable
// output the address of the int reference
// are the addresses the same or different? (insert answer)
// ** REFERENCE PARAMETER **
//
// create a function above main() called Square that takes in an int parameter
// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
// call the Square function with the int variable created in the REFERENCE section
// output the int variable to the console
// !! notice how the variable has not changed, this is because we only passed the value to the function !!
// change the Square function to take a int reference
// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
// ** POINTER VARIABLE **
//
// declare an int pointer, set it to nullptr (it points to nothing)
// set the int pointer to the address of the int variable created in the REFERENCE section
// output the value of the pointer
// what is this address that the pointer is pointing to? (insert answer)
// output the value of the object the pointer is pointing to (dereference the pointer)
// ** POINTER PARAMETER **
//
// create a function above main() called Double that takes in an int pointer parameter
// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
// !! make sure to dereference the pointer to set the value and not set the address !!
// call the Double function with the pointer created in the POINTER VARIABLE section
// output the dereference pointer
// output the int variable created in the REFERENCE section
// did the int variable's value change when using the pointer?