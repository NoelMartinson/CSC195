#pragma once
#include "BaseClass.h"

class Cat : public BaseClassName {
public:
    Cat(std::string name = "", short age = 0) {
        this->name = name;
        this->age = age;
    }

    void Read(std::ostream& ostream, std::istream& istream) override {
        ostream << "Enter cat's name: ";
        istream >> name;
        ostream << "Enter cat's age: ";
        istream >> age;
    }

    void Write(std::ostream& ostream) const override {
        ostream << "Cat - Name: " << name << ", Age: " << age << std::endl;
    }

    eType GetType() const override {
        return eType::CAT;
    }
};
