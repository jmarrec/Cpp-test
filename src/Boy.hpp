#ifndef BOY_HPP
#define BOY_HPP

#include <string>
#include "Person.hpp"

class Boy : public Person {

  public:

    /** @name Constructors and Destructors */
    //@{

    // Default ctor
    Boy();

    // Overloaded ctor, with a default argument
    // if I initialize with Person(10,"John") then this constructor is called with isGirl=True
    Boy(int age, std::string name);

    //@}
    /** @name Virtual Methods */
    //@{


    //@}
    /** @name Getters */
    //@{

    // If I want to redefine the behavior of getSex by hiding the base class implementation, I can redefine
    // std::string getSex() const;
    void isPretty() const override;


    //@}
    /** @name Setters */
    //@{


    //@}
    /** @name Others */
    //@{


  private:
    bool is_pretty = false;
};

#endif // BOY_HPP
