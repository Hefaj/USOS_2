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
    string s;

    this->Info();

    cout << "Podaj nowe imie:" << endl;
    cin >> s;
    this->name_ = s;
    cout << "Podaj nowe nazwisko:" << endl;
    cin >> s;
    this->surname_ = s;

    this->Info();
}

void Teacher::AddSubject(size_t id)
{
    przedmiot_id.push_back(id);
}

void Teacher::PrintSubject()
{
    for (auto s:przedmiot_id )
        cout << "ID: " << s << ", [subject_name]" << endl << endl;
}
