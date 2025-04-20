#pragma once
#include "BaseClass.h"

class Dog : public BaseClassName {
public:
    Dog(std::string name = "", short age = 0) {
        this->name = name;
        this->age = age;
    }

    void Read(std::ostream& ostream, std::istream& istream) override {
        ostream << "Enter dog's name: ";
        istream >> name;
        ostream << "Enter dog's age: ";
        istream >> age;
    }

    void Write(std::ostream& ostream) const override {
        ostream << "Dog - Name: " << name << ", Age: " << age << std::endl;
    }

    eType GetType() const override {
        return eType::DOG;
    }
};
