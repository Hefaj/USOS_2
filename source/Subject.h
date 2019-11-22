#include <string>
#include <iostream>
#include <vector>

#include <sstream>

using namespace std;

class Subject
{
    class Student_{
            size_t id_Student;
            int ocena_;
        public:
            Student_(size_t id) : id_Student(id), ocena_(0) {}
            Student_(size_t id, int g) : id_Student(id), ocena_(g) {}
            void Info()
            {
                cout.width(12);
                cout << left << "ID:";
                cout << id_Student;
                cout.width(12);
                cout << ", Ocena:";
                cout << ocena_ << endl;
            }
            size_t ID() { return id_Student; }
            int Grade() { return ocena_; }
            void SetGrade(int val) { this->ocena_ = val; }
    };

    size_t id_; // id przedmiotu
    string name_; // nazwa przedmiotu
    size_t id_Teacher_; // id prowadzącego
    std::vector<Student_> oceny_; // id studentow z ich ocenami

public:
    Subject(int, string, size_t);
    Subject(int, string, size_t, string);

    void Info();
    size_t ID();
    string NAME();
    size_t ID_Teacher();

    void AddStudent(size_t); // dodawanie studenta do przedmiotu
    void RemoveStudent(size_t);

    void PrintStudents();

    void PrintStudentGrade(size_t);

    void ChangeGrade(size_t, int);

    string StringAllStudents();
};
