#ifndef Employee_h
#define Employee_h
#include "Person.h"

namespace model
{
    class Employee: public Person {
        protected:
            std::string _jobTitle;
        public:
            Employee();
            Employee(std::string firstName, std::string lastName, int age);
            ~Employee();
            void setLastName(std::string name);
            void setJobTitle(std::string jobTitle);
    };
} // namespace model

#endif