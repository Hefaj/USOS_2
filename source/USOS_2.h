#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
#include "Teacher.h"
#include "Subject.h"

using namespace std;

class USOS_2
{
    std::vector<Student> students;
    std::vector<Teacher> teachers;
    std::vector<Subject> subjects;

public:

    void AddStudent(string, string);
    void RemoveStudent(size_t);

    void AddTeacher(string, string);
    void RemoveTeacher(size_t);

    void AddSubject(string, size_t);
    void RemoveSubject(size_t);

    void PrintAllStudent();
    void PrintAllTeacher();
    void PrintAllSubject();

    bool IsTeacher(size_t);
    bool IsStudent(size_t);
    bool IsSubject(size_t);

    Student* FindStudent(size_t);
    Subject* FindSubject(size_t);
    // wyswietl wszystkie przedmioty id studenta
    // wyswietl wszystkie przedmioty prowadzone przez id prowadzacy
};
