#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Subject
{
    class Student_{
        size_t id_Student;
        int ocena_;
    public:
        Student_(size_t id) : id_Student(id), ocena_(0) {}
        void Info() {cout << "ID: " << id_Student << ", Ocena: " << ocena_; }
    };

    size_t id_; // id przedmiotu
    string name_; // nazwa przedmiotu
    size_t id_Teacher_; // id prowadzącego
    std::vector<Student_> oceny_; // id studentow z ich ocenami

public:
    Subject(int, string, size_t);
    void Info();
    size_t ID();

    void AddStudent(size_t); // dodawanie studenta do przedmiotu
    // void RemoveStudent(size_t); // usuwanie studenta z przedmiotu

    void PrintStudents();

};
