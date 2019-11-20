#include "Subject.h"

Subject::Subject(int id, string name, size_t id_teacher) : id_(id), name_(name), id_Teacher_(id_teacher) {}


void Subject::Info()
{

    cout << "ID:";
    cout.width(10);
    cout << id_ << endl;
    cout << "Prowadzacy:";
    cout.width(3);
    cout << id_Teacher_ << endl;
    cout << "Nazwa:";
    cout.width(7);
    cout << name_ << endl << endl;
}

size_t Subject::ID(){ return id_; }

void Subject::AddStudent(size_t id)
{
    Student_ s(id);
    oceny_.push_back(s);
}

void Subject::PrintStudents()
{
    for (auto s:oceny_)
        s.Info();
}
