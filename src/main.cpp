#include <iostream>
#include <string>

#include "Person.hpp"
#include "Girl.hpp"
#include "Boy.hpp"

using namespace std;


void test_ctors() {

  cout << "\n\n================== test_ctors ====================";

  Person c1;
  Person c2(12, "Lolilo");
  Person c3(false);

  cout << "c1 is " << c1.getName() << " aged " << c1.getAge() << endl;

  cout << "Input the Name of c1" << endl;
  string c1_name;
  cin >> c1_name;
  c1.setName(c1_name);

  cout << "Input the age of c1" << endl;
  int c1_age;
  while ( !(cin >> c1_age) || (c1_age < 0) ) {
    cout << "Wrong input, please input a positive number" << endl;
    // MUST do that, otherwise it will get stuck in an infinite loop
    cin.clear();
    cin.ignore(INT_MAX, '\n');
  }
  c1.setAge(c1_age);

  cout << "c1 is named " << c1.getName() << " and aged " << c1.getAge() << endl;
  // Can't call c2.name directly, it's a private member!
  cout << "c2 is named " << c2.getName() << " and aged " << c2.getAge() << endl;


}


void test_inheritance() {


  cout << "\n\n================== test_inheritance ====================\n\n";
  cout << "\nc1\n";
  Person c1;
  c1.printIdentity();


  cout << "\nc2\n";
  Person c2(12, "Lolilo");
  c2.printIdentity();

  cout << "\nc3\n";
  Person c3(false);
  c3.printIdentity();

  cout << "\ng1\n";
  Girl g1;
  g1.printIdentity();

  cout << "\ng2\n";
  Girl g2(30, "Marie");
  g2.printIdentity();

  cout << "\nb1\n";
  Boy b1;
  b1.printIdentity();

  cout << "\nb2\n";
  Boy b2(30, "Julien");
  b2.printIdentity();

  // I didn't override getSex() so it calls Person::getSex()
  cout << "\n\nb1's sex is: " << b1.getSex() << endl;

  // I did override getSex() so it calls Girl::getSex()
  // Because the Person (Base Class) function is hidden by this new one
  cout << "\n\ng1's sex is: " << g1.getSex() << endl;

}

void test_virtual() {

  cout << "\n\n================== test_virtual ====================\n\n";
  Girl marie(30, "Marie");
  marie.printIdentity();
  Boy julien(30, "Julien");
  julien.printIdentity();

  Person * marie_ptr = &marie;
  Person * julien_ptr = &julien;

  cout << "\n\n**** isPretty is a virtual function, override in Boy, not in Girl **** \n\n";

  cout << "marie.isPretty(): "; marie.isPretty();
  cout << "julien.isPretty(): "; julien.isPretty();

  cout << "marie_ptr->isPretty(): "; marie_ptr->isPretty();
  // Because I have used a virtual function, this Person* pointer that points to a Boy actually calls the Boy::isPretty!
  cout << "julien_ptr->isPretty(): "; julien_ptr->isPretty();

  // marie.isPretty(): All Persons are pretty inside
  // julien.isPretty(): Julien is always pretty
  // marie_ptr->isPretty(): All Persons are pretty inside
  // julien_ptr->isPretty(): Julien is always pretty
  //
  cout << "\n\n**** getSex is not a virtual function, override in Girl, not in Boy **** \n\n";

  cout << "marie.getSex(): " << marie.getSex() << endl;
  cout << "julien.getSex(): " << julien.getSex() << endl;

  // Because I have NOT used a virtual function, this Person* pointer that points to a Girl actually calls the Person::getSex
  cout << "marie_ptr->getSex(): " << marie_ptr->getSex() << endl;
  cout << "julien_ptr->getSex(): " << julien_ptr->getSex() << endl;


}




bool marryTwoPersons(Person &p1, Person &p2, bool isThisARetrogradeCountry) {

  if ( (isThisARetrogradeCountry) && p1.getSex() == p2.getSex() ) {
      std::cout << "This is a retrograde country, same sex marriage isn't allowed!" << std::endl;
      return false;
  } else {
    // Set the is_married attribute
    p1.is_married = true;
    p2.is_married = true;
    // Set a pointer to the spouse
    p1.spouse_ptr = &p2;
    p2.spouse_ptr = &p1;
  }

  return true;

}

void test_pointer_to_class() {

  bool isThisARetrogradeCountry = true;
  bool success = false;

  cout << "\n\n================== test_pointer_to_class ====================\n\n";
  Girl marie(30, "Marie");
  marie.printIdentity();
  Boy julien(30, "Julien");
  julien.printIdentity();

  std::cout << "Marie is married is " << marie.isMarried() << ", julien is marred is " << julien.isMarried() << endl;

  cout << "Let's get married!\n";
  success = marryTwoPersons(marie, julien, isThisARetrogradeCountry);

  std::cout << std::boolalpha << "Marie is married is " << marie.isMarried() << ", julien is married is " << julien.isMarried() << endl;

  Person * marie_spouse = marie.getSpouse();
  if (marie_spouse) {
    cout << "Marie is married to " << marie_spouse->getName() << endl;
  }
  if (auto julien_spouse = julien.getSpouse()) {
    cout << "Julien is married to " << julien_spouse->getName() << endl;
  }


  // Make one of the spouse die

  marie.setAge(90);
  julien.setAge(90);
  cout << "Marie and Julien are now both 90 and have lived a long and happy life together\n";
  julien.die();

  cout << std::boolalpha << "marie is married is " << marie.isMarried() << endl;

  if (Person * marie_spouse = marie.getSpouse()) {
    cout << "Marie is married to " << marie_spouse->getName() << endl;
  } else {
    cout << "Marie isn't married (anymore)\n";
  }

  julien.printIdentity();


  cout << "\nTesting same sex marriage in a retrograde country\n";


  Boy gege(90, "Gerard");
  gege.printIdentity();
  Boy michel(90, "Michel");
  michel.printIdentity();


  success = marryTwoPersons(michel, gege, isThisARetrogradeCountry);
  if (success) {
    cout << "this shouldn't have worked\n";
  } else {
    cout << "RIOOOOOOT!!\n";
  }


}


void test_pointers_one() {
  char a='a', b='b';
  char * p = &a;
  char * &r = p;
  r = &b;
  cout << *p; // returns 'b'


}




void pass_by_value(int* p)
{
  //Allocate memory for int and store the address in p
  p = new int(2);
}

void pass_by_reference(int*& p)
{
  p = new int(3);
}
void test_pointers_two() {

  int a=1, b=1;

  int* p1 = &a;
  int* p2 = &b;

  pass_by_value(p1); //p1 will still be pointing to 1
  pass_by_reference(p2); //p2 's value is changed to point to the newly allocate memory, which is 3

  cout << "p1=" << *p1 << ",p2=" << *p2 << endl; // outputs p1=1, p2=3

}


int main() {

  // test_ctors();
  // test_inheritance();
  // test_virtual();
  // test_pointer_to_class();
  // test_one();
  test_pointers_two();

  return 0;
}
