#include <iostream>
#include <vector>
#include <string>

#include <fstream>
#include <sstream>

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

    USOS_2();
    ~USOS_2();


    void AddStudent(string, string);
    void AddTeacher(string, string);
    void AddSubject(string, size_t);

    void RemoveStudent(size_t);
    void RemoveTeacher(size_t);
    void RemoveSubject(size_t);

    void PrintAllStudent();
    void PrintAllTeacher();
    void PrintAllSubject();

    bool IsTeacher(size_t);
    bool IsStudent(size_t);
    bool IsSubject(size_t);

    Student* FindStudent(size_t);
    Subject* FindSubject(size_t);
    Teacher* FindTeacher(size_t);

    void PrintStudentGrades(size_t);
    void PrintStudentSList(Teacher*);
    void GetGrade(Teacher*);

    void PrintSubjects(size_t);

    void Migration();
    void Save();
};
