#include <iostream>
#include <string>
#include <vector>


#include "Person.h"
#include "APerson.h"

using namespace std;

class Student : public Person, APerson
{
    std::vector<size_t> lista_przed; // przedmioty studenta
public:
    Student(int, string, string);

    virtual void Info();
    virtual void EditProf();

    void AddSubject(size_t);
	void RemoveSubject(size_t);

    void PrintAllSubject();

    // lista przedmiotow na ktore chodzi z ocenami
};
