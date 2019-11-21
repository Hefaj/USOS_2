#include "Student.h"

Student::Student(int id, string name, string surname) : Person(id, name, surname) {}

void Student::Info()
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
    lista_przed.push_back(id);
}

void Student::RemoveSubject(size_t id)
{
    for( size_t i = 0; i<lista_przed.size();i++)
    {
        if (lista_przed[i] == id)
        {
            lista_przed.erase(lista_przed.begin()+i);
            cout << "Przedmiot pomyślnie usunięty." << endl << endl;
            break;
        }
    }
    cout << "Nie znaleziono takiego id." << endl << endl;
}

void Student::PrintAllSubject()
{
    for (auto s:lista_przed)
        cout << "ID: " << s << ", [subject_name]" << endl;
}
