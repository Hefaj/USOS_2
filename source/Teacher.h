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

    void AddSubject(size_t);
    void RemoveSubject(size_t);

    void PrintSubject();

    // lista studentow na danym przedmiocie z ich ocenami jezeli je prowadzi // moze to w przedmiocie
    // wystawianie ocen // moze to w przedmiocie
};
