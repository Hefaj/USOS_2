#pragma once
#include <string>

using namespace std;

class Person
{
protected:
    size_t id_;
    string name_;
    string surname_;
public:
    Person(size_t, string, string);
    size_t ID();
    string NAME();
    string SURNAME();
};
