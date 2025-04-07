#include <iostream>
#include <string>
using namespace std;

float getToppingPrice(const std::string& topping) {
    float pineapple = 3.0f;
    float bacon = 5.0f;
    float pepperoni = 2.0f;
    float olives = 1.25f;
    float sausage = 1.0f;

    if (topping == "pepperoni") {
        return pepperoni;
    }
    else if (topping == "bacon") {
        return bacon;
    }
    else if (topping == "olives") {
        return olives;
    }
    else if (topping == "sausage") {
        return sausage;
    }
    else if (topping == "pineapple") {
        return pineapple;
    }
    else {
        return 0;
    }
}

int main() {
    float basePrice = 10.0f;

    std::string topping1;
    std::string topping2;
    std::string topping3;
    std::string topping4;

        cout << "Enter topping 1 (pepperoni, bacon, olives, sausage, or pineapple): ";
        cin >> topping1;
        cout << "Enter topping 2 (pepperoni, bacon, olives, sausage, or pineapple): ";
        cin >> topping2;
        cout << "Enter topping 3 (pepperoni, bacon, olives, sausage, or pineapple): ";
        cin >> topping3;
        cout << "Enter topping 4 (pepperoni, bacon, olives, sausage, or pineapple): ";
        cin >> topping4;

    float totalPrice = basePrice;

    totalPrice += getToppingPrice(topping1);
    totalPrice += getToppingPrice(topping2);
    totalPrice += getToppingPrice(topping3);
    totalPrice += getToppingPrice(topping4);

    std::cout << "The total price is: " << totalPrice << std::endl;

    return 0;
}
