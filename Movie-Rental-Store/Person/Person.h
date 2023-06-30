#pragma once

#include <string>

class Person {
protected:
    unsigned int mId;
    std::string mName;
    std::string mAddress;

    static unsigned int mIdCounter;

public:
    Person();
    ~Person();

    void setId(unsigned int id);
    void setName(std::string name);
    void setAddress(std::string address);

    unsigned int getId() const;
    std::string getName() const;
    std::string getAddress() const;

    bool operator==(const Person& person) const;
};

