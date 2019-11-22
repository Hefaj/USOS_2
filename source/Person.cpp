#include "Person.h"

Person::Person(size_t id, string name, string surname) : id_(id), name_(name), surname_(surname) {}

size_t Person::ID() {return id_;}

string Person::NAME() { return name_; }
string Person::SURNAME(){ return surname_; }
