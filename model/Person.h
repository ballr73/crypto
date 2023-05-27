#ifndef Person_h
#define Person_h

#include <string>

namespace model 
{
    class Person {
        private:
            int _count = 0;
        protected:
            std::string _lastName;
            std::string _firstName;
            int _age; 
        public:       
            Person();
            Person(std::string firstName, std::string lastName, int age);
            std::string getFullName();
            std::string getFirstName();
            int getAge();
            void setAge(int age);
            void updatePerson();
    };
}     


#endif