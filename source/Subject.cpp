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
    {
        if (s.ID() == id)
        {
            cout << "ID przedmiotu: " << this->ID() << " : ";
            //if (s.Grade()==0) cout << "Brak oceny"; 
            //else cout << s.Grade();
            cout << s.Grade(); 
            cout << endl << endl;
        }
    }
}


void Subject::ChangeGrade(size_t id, int garde)
{

    for (size_t i = 0; i < oceny_.size(); i++)
    {
        if (oceny_[i].ID() == id)
        {
            cout << oceny_[i].Grade() << endl; 
            oceny_[i].SetGrade(garde);
            cout << oceny_[i].Grade() << endl;
            
            break;
        }
    }      
}