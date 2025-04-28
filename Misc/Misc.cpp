#include "Point.h"
#include <iostream>
#include <fstream>
#include <vector>

using names_t = std::vector<std::string>;

namespace math {
    template<typename T1, typename T2>
    T1 max(T1 a, T2 b) {
        if (a > b) {
            return a;
        }
        else if (a < b) {
            return b;
        }
        else if (a == b) {
            return a, b;
        }
    }
}

void print(const names_t& names) {
    for (std::string name : names) {
        std::cout << name << std::endl;
    }
}

void streamOut(std::ostream& ostream, std::string text) {
    ostream << text << std::endl;
}

void streamIn(std::istream& istream, std::string& text) {
}

int main(){

    streamOut(std::cout, "Lima");

    std::ofstream fstream("text.txt");
    streamOut(fstream, "Hello!");

    fstream.close();

    std::string text;
    streamIn(std::cin, text);
    std::cout << text << std::endl;

    math::ipoint_t p1(23, 34);
    math::ipoint_t p2(12, 10);
    math::ipoint_t p3;
    p3 = p1 + p2;

    //std::cout << p1.Add(p2) << std::endl;
    std::cout << p3.getX() << " " << p3.getY() << std::endl;

    std::cout << std::max(5, 10) << std::endl;
    std::cout << math::max(20, 10) << std::endl;

    names_t names{ "Agone", "Lunsos", "Elvain" }; 

    print(names);
}