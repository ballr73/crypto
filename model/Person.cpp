#include <string>
#include "Person.h"

namespace model
{
  Person::Person()
  {
  }

  Person::Person(std::string firstName, std::string lastName, int age) 
  {
    _firstName = firstName;
    _lastName = lastName;
    _age = age;
  }

  std::string Person::getFullName() 
  {
      return _firstName + " " + _lastName;
  }

  std::string Person::getFirstName()
  {
    return _firstName;
  }
  
  int Person::getAge() 
  {
    return _age;
  }

  void Person::setAge(int age) {
    _age = age;
  }

  void Person::updatePerson() {
    _count = _count + 1; 
  }
  
} // namespace model
