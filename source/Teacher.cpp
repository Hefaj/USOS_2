#include "Teacher.h"

Teacher::Teacher(int id, string name, string surname) : Person(id, name, surname) {}

void Teacher::Info()
{

    cout << "ID:";
    cout.width(8);
    cout << id_ << endl;
    cout << "Imię:";
    cout.width(6);
    cout << name_ << endl;
    cout << "Nazwisko:";
    cout.width(2);
    cout << surname_ << endl << endl;
}

void Teacher::EditProf()
{
    //edycja
    // co chcesz zmienic
    // switch
    // na co chcesz zmienic... itp
}
