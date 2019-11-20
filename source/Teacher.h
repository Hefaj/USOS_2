#include <iostream>
#include <string>
#include <vector>


#include "Person.h"
#include "APerson.h"

using namespace std;

class Teacher : public Person, APerson
{
    std::vector<size_t> przedmiot_id; // prowadzone przedmiotu
public:
    Teacher(int, string, string);

    virtual void Info();
    virtual void EditProf();

    // lista prowadzonych przedmiotow
    // lista studentow na danym przedmiocie z ich ocenami jezeli je prowadzi // moze to w przedmiocie
    // prowadzone przedmioty
    // wystawianie ocen // moze to w przedmiocie
};
