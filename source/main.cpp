// Kiedy pisałem ten kod to tylko ja i Bóg wiedział jak on działa.
// Teraz tylko Bóg wie.

/*
    Fix:
        - zmienic przyznawanie id, id daje na podstawie ilosci utworzonych obiektow
            jezeli usunie sie np 3 a sa 4, to dodanie nowego przypisze id = 3 gdzie czwarty ma id = 3
        rozwiązanie: odczytac id ostatniego i dodac jeden
            wada: id są unikalne i raz uzyty nawet po usunieciu obiektu nigdy sie nie pojawi jako nowe id
*/

#include <iostream>

#include "USOS_2.h"

using namespace std;

int ROOTView(USOS_2 &usos)
{
    char o;
    size_t id;
    string name, surname;

    while(1)
    {
        cout << "(1) Dodaj nowego studenta" << endl;
        cout << "(2) Dodaj nowego prowadzącego" << endl;
        cout << "(3) Dodaj nowy przedmiot" << endl;

        cout << "(4) Wyświetl wszystkich studentow" << endl;
        cout << "(5) Wyświetl wszystkich prowadzących" << endl;
        cout << "(6) Wyświetl wszystkie przedmioty" << endl;

        cout << "(7) Usuń studenta" << endl;
        cout << "(8) Usuń prowadzącego" << endl;
        cout << "(9) Usuń przedmiot" << endl;

        cout << "(x) Wybór profilu." << endl;

        cin >> o;

        switch(o)
        {
            case '1':
                cout << "Podaj imię studenta:" << endl;
                cin >> name;
                cout << "Podaj nazwisko studenta:" << endl;
                cin >> surname;
                usos.AddStudent(name,surname);

                break;
            case '2':
                cout << "Podaj imię prowadzącego:" << endl;
                cin >> name;
                cout << "Podaj nazwisko prowadzącego:" << endl;
                cin >> surname;
                usos.AddTeacher(name,surname);
                break;
            case '3':
                cout << "Podaj nazwe przedmiotu:" << endl;
                cin >> name;
                cout << "Podaj id prowadącego:" << endl;
                cin >> id;
                //if (IsNumber(id))
                    usos.AddSubject(name,id);
                //else
                //    cout << "Niepoprawna forma id." << endl;
                break;
            case '4':
                usos.PrintAllStudent();
                break;
            case '5':
                usos.PrintAllTeacher();
                break;
            case '6':
                usos.PrintAllSubject();
                break;
            case '7':
                cout << "Podaj id studenta:" << endl;
                cin >> id;
                usos.RemoveStudent(id);
                break;
            case '8':
                cout << "Podaj id prowadzącego:" << endl;
                cin >> id;
                usos.RemoveTeacher(id);
                break;
            case '9':
                break;
            case 'x':
                return 0;
                break;
            default:
                break;
        }
    }
}

int StudentView(USOS_2 &usos)
{
    char o;
    size_t id;

    Student *student;
    Subject *subject;

    cout << "Podaj swoje id:" << endl;
    cin >> id;

    if (usos.IsStudent(id))
        student = usos.FindStudent(id);
    else
    {
        cout << "Nie ma takiego studenta." << endl << endl;
        return 0;
    }

    while(1)
    {
        cout << "(1) Pokaż moje dane." << endl;
        cout << "(2) Edytuj moje dane." << endl;
        cout << "(3) Zapisz się na przedmiot." << endl;
        cout << "*(4) Wypisz się z przedmiotu" << endl;
        cout << "*(5) Zobacz oceny" << endl;

        cout << "(x) Wybór profilu." << endl;

        cin >> o;

        switch (o)
        {
            case '1':
                student->Info();
                break;
            case '2':
                student->EditProf();
                break;
            case '3':
                // pobranie id przedmiotu
                usos.PrintAllSubject();
                cout << "Podaj id przedmiotu, na który chcesz się wpisać:" << endl;
                cin >> id;
                // sprawdzenie czy przedmiot istnieje
                if (usos.IsSubject(id))
                {
                    // zaczepienie przedmiotu
                    subject = usos.FindSubject(id);
                    // dodanie studenta do przedmiotu
                    subject->AddStudent(student->ID());
                    // dodanie studentowi przedmiot
                    student->AddSubject(id);
                    cout << "Zapisano na przedmiot" << endl << endl;
                }
                else cout << "Nie ma przedmiotu o takim id." << endl << endl;
                break;
            case '4':
                // wypisanie sie z przedmiotu
                break;
            case '5':
                // wyswietlenie wszystkich przedmiotow z ocenami
                break;
            case 'x':
                return 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    char o;

    USOS_2 usos;

    cout.width(20);
    cout << "**********" << endl;
    cout.width(20);
    cout << "* USOS_2 *" << endl;
    cout.width(20);
    cout << "**********" << endl;

    while(1)
    {
        cout << "Wybierz profil, z którego chcesz korzystać:" << endl;
        cout << "(1) ROOT" << endl;
        cout << "(2) Student" << endl;
        cout << "*(3) Prowadzący" << endl;
        cout << "(x) Zakończ" << endl;

        cin >> o;

        switch (o)
        {
            case '1':
                ROOTView(usos);
                break;
            case '2':
                StudentView(usos);
                break;
            case '3':
                //TeacherView(usos);
                break;
            case 'x':
                return 0;
            default:
                break;
        }
    }



    return 0;
}
