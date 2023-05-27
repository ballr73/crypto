#ifndef Worker_h
#define Worker_h

#include <string>
#include "Person.h"
using namespace model;
namespace model
{
    class Worker
    {
        private:
            Person *_person;
            int _count;
        public:
            Worker();
            Worker(Person *p);
            ~Worker();
            void DoWork(Person *p);
    };    
} // namespace model


#endif