#include "Subject.h"

Subject::Subject(int id, string name, size_t id_teacher) : id_(id), name_(name), id_Teacher_(id_teacher) {}

Subject::Subject(int id, string name, size_t id_teacher, string str) : id_(id), name_(name), id_Teacher_(id_teacher)
{
    stringstream iss(str);

    size_t _id;
    int ocena;

    while ( iss >> _id >> ocena )
        {
            Student_ s_(_id, ocena);
            oceny_.push_back(s_);
        }
}


void Subject::Info()
{

    cout << "ID:";
    cout.width(11);
    cout << id_ << endl;
    cout << "Prowadzacy:";
    cout.width(3);
    cout << id_Teacher_ << endl;
    cout << "Nazwa:";
    cout.width(9);
    cout << name_ << endl << endl;
}

size_t Subject::ID(){ return id_; }
string Subject::NAME() {return name_; }
size_t Subject::ID_Teacher(){return id_Teacher_; }

void Subject::AddStudent(size_t id)
{
    Student_ s(id);
    oceny_.push_back(s);
}

void Subject::RemoveStudent(size_t id)
{
    for(auto s = oceny_.begin(); s != oceny_.end();)
    {
        if (s->ID() == id)
        {
            oceny_.erase(s);
             cout << "Wypisano z przedmiotu." << endl << endl;
            break;
        }
        s++;
    }
}

void Subject::PrintStudents()
{
    for (auto s:oceny_)
        s.Info();

    cout << endl;
}


void Subject::PrintStudentGrade(size_t id)
{
    for (auto s:oceny_)
        if (s.ID() == id)
        {
            //s.Info();
            cout.width(12);
            cout << left << "Nazwa:";
            cout << name_;
            cout.width(12);
            cout << ", Ocena:";
            cout << s.Grade() << endl;
        }
}


void Subject::ChangeGrade(size_t id, int garde)
{

    for (size_t i = 0; i < oceny_.size(); i++)
    {
        if (oceny_[i].ID() == id)
        {
            oceny_[i].SetGrade(garde);
            break;
        }
    }
}

string Subject::StringAllStudents()
{
    string s_ = "";

    for (auto s:oceny_)
    {
        s_ += " " + to_string(s.ID()) + " " + to_string(s.Grade());
    }
    return s_;
}
