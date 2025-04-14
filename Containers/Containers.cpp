#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

unsigned int GetHash(std::string str) {
	int hash = 0;
	for (char c : str)
	{
		hash = hash * 31 + (int)c;
	}
	return hash;
}

void arrayDays() {
	//array
	string ar = " Array";
	cout << ar << endl;
	//array

	array<string, 7> a = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	//Prints how mant objects are in the array
	cout << a.size() << endl;

	//Prints a loop of each item in the array
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
}

void vectorNumbers() {
	//vector
	string v = "\n Vector";
	cout << v << endl;
	//vector

	vector<int> vec = { 1,2,3,4,5 };

	//Creates two ints at the end
	vec.push_back(6);
	vec.push_back(7);

	//Removes the very last int
	vec.pop_back();

	//Shows the current size of the vector
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}

void listFruits() {
	//list
	string l = "\n List";
	cout << l << endl;
	//list

	list<string> lst = { "Apple", "Pear", "Grape" };

	//Creates an item at the front and back
	lst.push_front("Cherry");
	lst.push_back("Orange");

	//Removws an item
	lst.remove("Pear");

	for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
		cout << *it << " ";
	}

}

void mapGroceries() {
	//(ordered) map
	string ma = "\n Map \n";
	cout << ma << endl;
	//map
	map<string, int> m;

	//Insert key-value pairs
	m["bread"] = 2;
	m["ground beef"] = 3;
	m["frozen meals"] = 8;

	//Update value for an existing key
	m["ground beef"] = 2;
	
	//Print the map
	for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}

	//unordered map
	unordered_map<int, string> um;
	um[1234] = "allmendiger";
	um[5687] = "oxborow";
	cout << um[5687] << endl;
	
	string name = "Raymond";
	int hash = GetHash(name);
	cout << hash << endl;
	int data[10];
	data[hash % 10] = 84025;


	hash = GetHash("Raymond");
	cout << data[hash % 10] << endl;

}

int main() {

	arrayDays();

	vectorNumbers();

	listFruits();

	mapGroceries();

	return 0;
}