#include <iostream>
#include "Boy.hpp"


Boy::Boy()
: Person(false) // Call the superclass constructor in the subclass' initialization list with isGirl=false
{
  std::cout << "Default Boy ctor" << std::endl;
}

Boy::Boy(int age, std::string name) : Person(age, name, false) {
  std::cout << "Overloaded Boy ctor" << std::endl;
}


void Boy::isPretty() const {
  // this->name fails because it's a private member of Person
  std::cout << "Boy " << getName() << " is pretty? " << this->is_pretty << std::endl;
}
