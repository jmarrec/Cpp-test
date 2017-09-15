#ifndef GIRL_HPP
#define GIRL_HPP

#include <string>
#include "Person.hpp"

class Girl : public Person {

  public:

    /** @name Constructors and Destructors */
    //@{

    // Default ctor
    Girl();

    // Overloaded ctor, with a default argument
    // if I initialize with Person(10,"John") then this constructor is called with isGirl=True
    Girl(int age, std::string name);

    //@}
    /** @name Getters */
    //@{

    // I want to redefine the behavior of getSex, this hides the base class implementation
    std::string getSex() const;

    void isPretty() const override;

    //@}
    /** @name Setters */
    //@{


    //@}
    /** @name Others */
    //@{


  private:
    bool is_pretty = true;
};

#endif // GIRL_HPP
