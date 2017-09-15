// ifndef endif guarantees that the header will not be included twice
#ifndef PERSON_H
#define PERSON_H

#include <string>


// Function outside the scope of the current class
// bool marryTwoPersons(Person &p1, Person &p2, bool isThisARetrogradeCountry);


class Person {

  public:

    /** @name Constructors and Destructors */
    //@{

    // Default ctor
    Person();

    // Overloaded ctor, with a default argument
    // if I initialize with Person(10,"John") then this constructor is called with isGirl=True
    Person(int age, std::string name, bool isGirl=true);

    // Another overloaded ctor. If I pass a default value (isGirl=true) it will conflict with the default ctor!
    Person(bool isGirl);

    // Destructor
    // ~Person();

    //@}

    /** @name Virtual Methods */
    //@{

    virtual void isPretty() const;

    //@}
    /** @name Getters */
    //@{

    int getAge() const;

    std::string getName() const;

    std::string getSex() const;

    bool isMarried() const;

    // I'd like to use boost::optional<Person> here instead...
    // But I don't want to include boost, so I return a pointer instead
    Person* getSpouse() const;

    //@}
    /** @name Setters */
    //@{

    void setAge(int age);

    void setName(std::string name);

    void die();

    //@}
    /** @name Others */
    //@{
    void printIdentity() const;


  private:
    int age;
    std::string name;
    bool is_married=false;
    // Person spouse, a pointer to another person
    Person * spouse_ptr = nullptr;
    bool is_alive=true;


    // Friend function, grants access to the private members of this class to the function
    friend bool marryTwoPersons(Person &p1, Person &p2, bool isThisARetrogradeCountry);

  protected:
    // I actually want derived class to be able to access sex (because I'm implementing a variant of getSex in girl)
    std::string sex;


};

#endif // PERSON_H
