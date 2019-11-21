#include "Teacher.h"

Teacher::Teacher(int id, string name, string surname) : Person(id, name, surname) {}

void Teacher::Info()
{
    cout.width(12);
    cout << left << "ID:";
    cout.width(12);
    cout << id_ << endl;
    cout << "Imię:";
    cout.width(12);
    cout << name_ << endl;
    cout << "Nazwisko:";
    cout.width(12);
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

void Teacher::RemoveSubject(size_t id)
{
    for( size_t i = 0; i<przedmiot_id.size();i++)
    {
        if (przedmiot_id[i] == id)
        {
            przedmiot_id.erase(przedmiot_id.begin()+i);
            break;
        }
    }
    cout << "Nie znaleziono takiego id." << endl << endl;
}

void Teacher::PrintSubject()
{
    for (auto s:przedmiot_id )
        cout << "ID: " << s << ", [subject_name]" << endl << endl;
}
