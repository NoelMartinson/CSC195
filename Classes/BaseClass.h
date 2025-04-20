#pragma once
#include <iostream>
#include <string>

class BaseClassName {
public:
    enum class eType { CAT, DOG };

    virtual ~BaseClassName() {}

    virtual void Read(std::ostream& ostream, std::istream& istream) = 0;

    virtual void Write(std::ostream& ostream) const = 0;

    virtual eType GetType() const = 0;

    virtual std::string GetName() const { return name; }

protected:
    std::string name;
    short age;
};
