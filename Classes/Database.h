#pragma once
#include "BaseClass.h"
#include "Derived1.h"
#include "Derived2.h"
#include <iostream>
#include <vector>
#include <string>

class Database {
public:
    ~Database() {
        for (BaseClassName* obj : objects) {
            delete obj;
        }
    }

    void Create(BaseClassName::eType type) {
        BaseClassName* obj = nullptr;
        switch (type) {
        case BaseClassName::eType::CAT:
            obj = new Cat();
            break;
        case BaseClassName::eType::DOG:
            obj = new Dog();
            break;
        default:
            std::cout << "Unknown type." << std::endl;
            return;
        }
        obj->Read(std::cout, std::cin); 
        objects.push_back(obj); 
    }

    void DisplayAll() {
        for (BaseClassName* obj : objects) {
            obj->Write(std::cout); 
        }
    }

    void Display(const std::string& name) {
        for (BaseClassName* obj : objects) {
            if (obj->GetName() == name) {
                obj->Write(std::cout);
                return;
            }
        }
        std::cout << "Name not found" << std::endl;
    }

    void Display(BaseClassName::eType type) {
        for (BaseClassName* obj : objects) {
            if (obj->GetType() == type) {
                obj->Write(std::cout); 
            }
        }
    }

private:
    std::vector<BaseClassName*> objects;
};
