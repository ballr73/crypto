#include "Employee.h"
#include <iostream>

namespace model
{
    Employee::Employee() {

    }
    Employee::Employee(std::string firstName, std::string lastName, int age) : Person(firstName, lastName, age) { 

    }
    Employee::~Employee() {
        std::cout << "Destructor Called!" << "\n";
    }
    void Employee::setLastName(std::string lastName) {
       _lastName = lastName;
       return;
    }
    void Employee::setJobTitle(std::string jobTitle) {
        _jobTitle = jobTitle;
    }
} // namespace model
