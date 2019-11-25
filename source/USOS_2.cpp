#include "USOS_2.h"

USOS_2::USOS_2()
{
    Migration();
}


USOS_2::~USOS_2()
{
    Save();
}


void USOS_2::AddStudent(string name, string surname)
{
    Student s(students.size(), name, surname);
    students.push_back(s);
    cout << "Student dodany pomyślnie:" << endl;

    s.Info();
}

void USOS_2::AddTeacher(string name, string surname)
{
    Teacher t(teachers.size(), name, surname);
    teachers.push_back(t);
    cout << "Prowadzący dodany pomyślnie:" << endl << endl;

    t.Info();
}

void USOS_2::AddSubject(string name, size_t id_teacher)
{
    Teacher* teacher;
    // czy taki nauczycil istnije?
    if (IsTeacher(id_teacher))
    {
        Subject t(subjects.size(), name, id_teacher);
        subjects.push_back(t);

        teacher = FindTeacher(id_teacher);
        teacher->AddSubject(t.ID());
        cout << "Przedmiot dodany pomyślnie:" << endl << endl;
        t.Info();
    }
    else
        cout << "Niepoprawne id prowadzącego" << endl << endl;
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

    //cout << "Nie znaleziono takiego id." << endl;
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

    //cout << "Nie znaleziono takiego id." << endl;
}

void USOS_2::RemoveSubject(size_t id)
{
    for(auto s = subjects.begin(); s != subjects.end();)
    {
        if (s->ID() == id)
        {
            s->Info();
            subjects.erase(s);
            cout << "Przemiot został usuiety." << endl;
            break;
        }
        s++;
    }

    for (auto i = students.begin(); i != students.end(); ++i)
        i->RemoveSubject(id);


    for (auto i = teachers.begin(); i != teachers.end(); ++i)
        i->RemoveSubject(id);


    //cout << "Nie znaleziono przemiotu o takim id." << endl;
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

Teacher* USOS_2::FindTeacher(size_t id)
{
    for (size_t i = 0; i < teachers.size(); i++)
        if (teachers[i].ID() == id) return &teachers[i];
    return &teachers[0];
}

Student* USOS_2::FindStudent(size_t id)
{
    for (size_t i = 0; i < students.size(); i++)
        if (students[i].ID() == id) return &students[i];
    return &students[0];
}

Subject* USOS_2::FindSubject(size_t id)
{
    for (size_t i = 0; i < subjects.size(); i++)
        if (subjects[i].ID() == id) return &subjects[i];
    return &subjects[0];
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

void USOS_2::PrintStudentGrades(size_t id)
{
    for (auto s:subjects)
        s.PrintStudentGrade(id);
    cout << endl;
}

void USOS_2::PrintSubjects(size_t id)
{
    for (auto s:subjects)
    {
        if (s.ID() == id)
            cout << "ID: " << s.ID() << ", " << s.NAME() << endl << endl;
    }
}

void USOS_2::PrintStudentSList(Teacher *teacher)
{
    size_t id;
    Subject *subject;

    //teacher->PrintSubject();
    PrintSubjects(teacher->ID());
    cout << "Wybierz id przemiotu" << endl;
    cin >> id;

    subject = FindSubject(id);
    subject->PrintStudents();
}

void USOS_2::GetGrade(Teacher *teacher)
{
    size_t id, id_;
    Subject *subject;
    int grade;

    PrintSubjects(teacher->ID());
    cout << "Wybierz id przemiotu" << endl;
    cin >> id;

    subject = FindSubject(id);
    subject->PrintStudents();

    cout << "Wybierz id studenta:" << endl;
    cin >> id_;
    if (IsStudent(id_))
    {
        cout << "Podaj ocene:" << endl;
        cin >> grade;
        subject->ChangeGrade(id_, grade);
    }
    else cout << "Niepoprawne id studenta." << endl << endl;
}

void USOS_2::Migration()
{
    string name_file = "db/Student.txt";
    string name, surname;
    size_t id;

    string line;
    string znak = "*";

    ifstream file (name_file);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            size_t pos;

            pos = line.find(znak);
            id = stoi(line.substr(0, pos));
            line.erase(0, pos+1);

            pos = line.find(znak);
            name = line.substr(0, pos);
            line.erase(0, pos+1);

            pos = line.find(znak);
            surname = line.substr(0, pos);
            line.erase(0, pos+2);

            stringstream iss(line);
            size_t number;
            vector<size_t> Numbers;
            while ( iss >> number )
                Numbers.push_back(number);

            Student s(id, name, surname, Numbers);
            students.push_back(s);
        }

        file.close();
    }
    else cout << "Nie mogę dorwać się do " << name_file  << endl;

    name_file = "db/Teacher.txt";

    file.open(name_file);

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            size_t pos;

            pos = line.find(znak);
            id = stoi(line.substr(0, pos));
            line.erase(0, pos+1);

            pos = line.find(znak);
            name = line.substr(0, pos);
            line.erase(0, pos+1);

            pos = line.find(znak);
            surname = line.substr(0, pos);
            line.erase(0, pos+1);

            stringstream iss(line);
            size_t number;
            vector<size_t> Numbers;
            while ( iss >> number )
                Numbers.push_back(number);

            Teacher t(id, name, surname, Numbers);
            teachers.push_back(t);
        }
        file.close();
    }
    else cout << "Nie mogę dorwać się do " << name_file  << endl;


    name_file = "db/Subject.txt";

    file.open(name_file);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            size_t pos;
            size_t id_t;

            pos = line.find(znak);
            id = stoi(line.substr(0, pos));
            line.erase(0, pos+1);

            pos = line.find(znak);
            name = line.substr(0, pos);
            line.erase(0, pos+1);

            pos = line.find(znak);
            id_t = stoi(line.substr(0, pos));
            line.erase(0, pos+1);


            Subject s(id, name, id_t, line);
            subjects.push_back(s);
        }
        file.close();
    }
    else cout << "Nie mogę dorwać się do " << name_file  << endl;
}

void USOS_2::Save()
{
    string name_file = "db/Student.txt";

    ofstream file (name_file);
    if (file.is_open())
    {
        for (auto s:students)
        {
            file << s.ID() << "*" << s.NAME() << "*" << s.SURNAME() << "*";
            file << s.StringAllSubject() << "\n";
        }

        file.close();
    }
    else cout << "Nie mogę dorwać się do " << name_file  << endl;

    name_file = "db/Teacher.txt";

    file.open(name_file);
    if (file.is_open())
    {
        for (auto s:teachers)
        {
            file << s.ID() << "*" << s.NAME() << "*" << s.SURNAME()  << "*";
            file << s.StringAllSubject() << "\n";
        }

        file.close();
    }
    else cout << "Nie mogę dorwać się do " << name_file  << endl;

    name_file = "db/Subject.txt";

    file.open(name_file);
    if (file.is_open())
    {
        for (auto s:subjects)
        {
            file << s.ID() << "*" << s.NAME() << "*" << s.ID_Teacher() << "*";
            file << s.StringAllStudents() << "\n";
        }

        file.close();
    }
    else cout << "Nie mogę dorwać się do " << name_file  << endl;
}

