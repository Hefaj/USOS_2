#include <iostream>
#include <string>
#include <vector>


#include "Person.h"
#include "APerson.h"

using namespace std;

class Student : public Person, APerson
{
    std::vector<size_t> przedmiot_id; // przedmiotu studenta

public:
    Student(int, string, string);
    virtual void Info();
    virtual void EditProf();

    void AddSubject(size_t);

    // lista przedmiotow na ktore chodzi z ocenami
};
