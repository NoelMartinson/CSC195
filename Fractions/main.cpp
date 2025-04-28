#include <iostream>
#include "fraction.h"

using namespace math;

int main() {
    Fraction<int> a(1, 2);
    Fraction<int> b(3, 4);
    Fraction<int> result;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    result = a + b;
    std::cout << "a + b = " << result << "\n";

    result = a - b;
    std::cout << "a - b = " << result << "\n";

    result = a * b;
    std::cout << "a * b = " << result << "\n";

    result = a / b;
    std::cout << "a / b = " << result << "\n";

    std::cout << std::boolalpha;
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";

    Fraction<int> userFrac;
    std::cout << "Enter a fraction (format: numerator/denominator): ";
    std::cin >> userFrac;
    if (std::cin) {
        std::cout << "You entered: " << userFrac << "\n";
        std::cout << "As double: " << userFrac.toDouble() << "\n";
    } else {
        std::cout << "Invalid input!\n";
    }

    return 0;
}
