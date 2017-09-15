#include <iostream>
#include "Girl.hpp"


Girl::Girl() {
  std::cout << "Default girl ctor" << std::endl;
}

Girl::Girl(int age, std::string name) : Person(age, name) {
  std::cout << "Overloaded girl ctor" << std::endl;
}

std::string Girl::getSex() const {
  std::cout << "DUH IMMA GIRL" << std::endl;
  return this->sex;
}

void Girl::isPretty() const {
  // this->name fails because it's a private member of Person
  if (this->getName() == "Marie") {
    std::cout << "Marie is the prettiest!" << std::endl;
  } else {
    std::cout << "Girl " << this->getName() << " is pretty? " << this->is_pretty << std::endl;
  }
}
