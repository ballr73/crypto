#include <iostream>
#include <string>
#include "Worker.h"
#include "Person.h"
namespace model
{
    Worker::Worker() {
        _count = 0;
    }

    Worker::Worker(model::Person *p) {
        Worker::_person = p;
        _count = 0;
    }   
    Worker::~Worker() {
        std::cout << "Woker deallocated" << "\n";        
    }
    void Worker::DoWork(Person *p) {
        try
        {
            if(_person == NULL) {
                _person = p;
            }
            if(_person->Person::getFirstName() == "error")
            {
                throw "Ilegal Name!";
            }
            for (int i = 0; i < 100; i++)
            {
                _count = _count + 1;
                _person->Person::updatePerson();
                std::cout << "Doing Work for : "  << _person->Person::getFullName() << " - " << _count << "\n";
            }
        }
        catch(const char* msg)
        {
            std::cerr << msg << "\n";
        }
    } 
} // namespace model
