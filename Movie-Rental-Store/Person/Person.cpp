#include "Person.h"

/******************************************************************************************
 * Person class implementation
 *****************************************************************************************/

 /**
  * @brief Static member variable to keep track of the number of persons.
  * @note This is a protected member variable, so it is accessible by the derived classes.
  *       This variable is initialized to 1, because the first person will have an id of 1.
  *       This is because the id is incremented after it is assigned to the person.
  *       So the first person will have an id of 1, the second person will have an id of 2, etc.
  **/
unsigned int Person::mIdCounter = 1;
Person::Person() {
    mId = mIdCounter++;
    mName = "";
    mAddress = "";
}

Person::~Person() {}

void Person::setId(unsigned int id) { mId = id; }
void Person::setName(std::string name) { mName = name; }
void Person::setAddress(std::string address) { mAddress = address; }

unsigned int Person::getId() const { return mId; }
std::string Person::getName() const { return mName; }
std::string Person::getAddress() const { return mAddress; }

/**
 * @brief Overloaded operator to compare two Person objects.
 * @param Person The Person object to compare with.
 * @return True if the two Person objects are the same, false otherwise.
 **/
bool Person::operator==(const Person& person) const {
    return mId == person.mId;
}

/*****************************************************************************************/
