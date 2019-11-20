#include "Student.h"

Student::Student(int id, string name, string surname) : Person(id, name, surname) {}

void Student::Info()
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

void Student::EditProf()
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

void Student::AddSubject(size_t id)
{
    przedmiot_id.push_back(id);
}
