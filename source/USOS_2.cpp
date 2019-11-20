#include "USOS_2.h"

void USOS_2::AddStudent(string name, string surname)
{
    Student s(students.size(), name, surname);
    students.push_back(s);
    cout << "Student dodany pomyślnie:" << endl;

    s.Info();
}

void USOS_2::RemoveStudent(size_t id)
{
    for(auto s = students.begin(); s != students.end();)
    {
        if (s->ID() == id)
        {
            s->Info();
            students.erase(s);
             cout << "Student pomyślnie usunięty." << endl << endl;
            break;
        }
        s++;
    }

    cout << "Nie znaleziono takiego id." << endl;
}

void USOS_2::RemoveTeacher(size_t id)
{
    for(auto s = teachers.begin(); s != teachers.end();)
    {
        if (s->ID() == id)
        {
            s->Info();
            teachers.erase(s);
             cout << "Prowadzący pomyślnie usunięty." << endl << endl;
            break;
        }
        s++;
    }

    cout << "Nie znaleziono takiego id." << endl;
}

void USOS_2::RemoveSubject(size_t id)
{
    for(auto s = subjects.begin(); s != subjects.end();)
    {
        if (s->ID() == id)
        {
            s->Info();
            subjects.erase(s);
             cout << "Przedmiot pomyślnie usunięty." << endl << endl;
            break;
        }
        s++;
    }

    cout << "Nie znaleziono takiego id." << endl;
}

void USOS_2::AddTeacher(string name, string surname)
{
    Teacher t(teachers.size(), name, surname);
    teachers.push_back(t);
    cout << "Prowadzący dodany pomyślnie:" << endl << endl;

    t.Info();
}

bool USOS_2::IsTeacher(size_t id)
{
    for (auto t:teachers)
        if (t.ID() == id) return true;
    return false;
}

bool USOS_2::IsStudent(size_t id)
{
    for (auto s:students)
        if (s.ID() == id) return true;
    return false;
}

bool USOS_2::IsSubject(size_t id)
{
    for (auto s:subjects)
        if (s.ID() == id) return true;
    return false;
}

Student* USOS_2::FindStudent(size_t id)
{
    for (size_t i = 0; i < students.size(); i++)
        if (students[i].ID() == id) return &students[i];
}

Subject* USOS_2::FindSubject(size_t id)
{
    for (size_t i = 0; i < subjects.size(); i++)
        if (subjects[i].ID() == id) return &subjects[i];
}

void USOS_2::AddSubject(string name, size_t id_teacher)
{
    // czy taki nauczycil istnije?
    if (IsTeacher(id_teacher))
    {
        Subject t(subjects.size(), name, id_teacher);
        subjects.push_back(t);
        cout << "Przedmiot dodany pomyślnie:" << endl << endl;
        t.Info();
    }
    else
        cout << "Niepoprawne id prowadzącego" << endl << endl;
}

void USOS_2::PrintAllStudent()
{
    cout << "Liczba wszystkich studentów: " << students.size() << endl;

    for (auto s:students)
        s.Info();
}

void USOS_2::PrintAllTeacher()
{
    cout << "Liczba wszystkich prowadzących: " << teachers.size() << endl;

    for (auto s:teachers)
        s.Info();
}

void USOS_2::PrintAllSubject()
{
    cout << "Liczba wszystkich przedmiotów: " << subjects.size() << endl;

    for (auto s:subjects)
        s.Info();
}
