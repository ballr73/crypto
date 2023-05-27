#include <iostream>
#include "model/Person.h"
#include "model/Employee.h"
#include "model/Worker.h"
using namespace model;

const int PI = 12;
enum Flavor: unsigned short int
{
    Vanilla,
    Chocolate,
    Strawberry,
    Mint
};
void updatePerson(Person *p)
{
    p->Person::setAge(48);
}

void updateNumber(int *number)
{
    *number = *number + 1;
    return;
}

int main() {
    Flavor flavour = Chocolate;
    std::cout << flavour << "\n";
    int var = 20;
    int *ip;

    ip = &var;

    std::cout << "Value of var variable: ";
    std::cout << var << std::endl;

    // print the address stored in ip pointer variable
    std::cout << "Address stored in ip variable: ";
    std::cout << ip << std::endl;

    // access the value at the address available in pointer
    std::cout << "Value of *ip variable: ";
    std::cout << *ip << std::endl;

    int y, z = 15;
    int x;
    x = 1;
    
    std::cout << "Number: " << x << "\n";
    updateNumber(&x);
    std::cout << "Number: " << x << "\n";

    std::string firstName;
    std::cout << "Enter your first name: ";
    getline(std::cin, firstName);

    // cout << fullName;
    // cout << x;

    Person person(firstName, "Ball", 33);
    Person* p = &person;
    
    std::cout << p->Person::getAge() << "\n";
    updatePerson(&person);
    std::cout << p->Person::getAge() << "\n";

    // Worker work(&person);
    // work.Worker::DoWork();

    // Worker *w = &work;
    // w->Worker::DoWork();

    Worker* worker = new Worker(&person);
    worker->Worker::DoWork(NULL);

    std::cout << p->Person::getAge() << "\n";

    Employee employee("Ethan", "Ball", 12);
    employee.setLastName("Smith");
    employee.setAge(44);
    employee.setJobTitle("Chef");

    Worker *anotherWorker = new Worker(&employee);
    anotherWorker->DoWork(NULL);
    
    Worker *workers = new Worker[10];
    for (int i = 0; i < 10; i++)
    {
        workers[i].Worker::DoWork(&employee);
    }
    
    delete [] workers;
    std::cout << employee.getFullName() << "\n";
    std::cout << employee.getFullName() << "\n";
    // *&x = 22;
    // std::cout << x << '\n'; // print the value of variable x
    // std::cout << &x << '\n'; // print the memory address of variable x
    // std::cout << *&x << '\n';
    return 0;
}
