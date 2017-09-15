#include <iostream>
#include <string>
#include "Person.hpp"

// Default ctor
Person::Person() {

  std::cout << "Default Person constructor called" << std::endl;
  age = 0;
  name = "John Doe";
  sex = "Female";
}

/*
 *Overloaded ctor, uses initializer list
 *If you provide arguments that have the same name as attributes, eg std::string name when you have a Person `name`attribute
 *and you just use `name` in the function's body, it will use the argument, not the attribute!
 */
Person::Person(int n, std::string s, bool isGirl) : age(n), name(s) {

  if (isGirl) {
    this->sex = "Female";
  } else {
    this->sex = "Male";
  }
  // this-> age = 14;
  // this->name = "Overwritten name";
  std::cout << "Overloaded Person constructor called"
            <<   " with a " << sex << " named " << name << " and aged "
            << age << std::endl;
}

/** Overloaded Ctor with a bool argument for female/male */
Person::Person(bool isGirl) {

  std::cout << "Overloaded Person ctor with one bool argument called" << std::endl;

  if (isGirl) {
    age = 0;
    name = "Jane Doe";
    sex = "Female";

  } else {
    age = 0;
    name = "John Doe";
    sex = "Male";
  }
}

// Destructor
/*
 *Person::~Person() {
 *  std::cout << "Person Destructor" << std::endl;
 *  if (this->isMarried()) {
 *    // Get the spouse by dereferencing the pointer
 *    Person spouse = *spouse_ptr;
 *    // Set the spouse's spouse_ptr to null
 *    spouse.spouse_ptr = nullptr;
 *    // And the is_married to false
 *    spouse.is_married = false;
 *  }
 *}
 */


/*
 *This method basically deletes a person. It marks the is_alive bool to false, and if it had a spouse,
 *the spouse is changed to be no longer married
 */
void Person::die() {
  std::cout << getName() << " was " << getAge() << ". ";
  if (this->isMarried()) {
    // Get the spouse by dereferencing the pointer
    // Person spouse = *spouse_ptr; ==> This will not work, it doesn't modify the base object
    std::cout << "He was married to " << this->spouse_ptr->getName() << ". ";

    // Set the spouse's spouse_ptr to null
    this->spouse_ptr->spouse_ptr = nullptr;

    // And the is_married to false
    this->spouse_ptr->is_married = false;

  }
  std::cout << std::endl;

  // delete this;
  this->is_alive = false;
  // this->~Person();
}


void Person::isPretty() const {
  std::cout << "All Persons are pretty inside" << std::endl;
}

int Person::getAge() const {
  return age;
}
std::string Person::getName() const {
  return name;
}

std::string Person::getSex() const {
  return "Person is " + this->sex;
}

void Person::setAge(int age) {
  this->age = age;
}

void Person::setName(std::string name) {
  this->name = name;
}

void Person::printIdentity() const {
  // Depending on whether you have declared a const function, this will fail (if const) or not (if not const)
  // To be safe, functions that aren't supposed to modify attributes such as this one should be declared as const
  // age = 189;
  if (this->is_alive) {
    std::cout << "The " << this->sex << " named " << getName() << " is aged " << age << std::endl;
  } else {
    std::cout << "The " << this->sex << " named " << getName() << " was aged " << age << " when he passed away" << std::endl;
  }
}

bool Person::isMarried() const {
  return is_married;
}

Person* Person::getSpouse() const {
  if (isMarried()) {
    return spouse_ptr;
  } else {
    return nullptr;
  }
}




