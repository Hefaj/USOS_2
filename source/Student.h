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
    Student(int, string, string, vector<size_t>);


    virtual void Info();
    virtual void EditProf();

    void AddSubject(size_t);
	int RemoveSubject(size_t);

    void PrintAllSubject();
    string StringAllSubject();
};
