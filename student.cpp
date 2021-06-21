#include "student.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Student::Student()
{
    name = "";
    age = 0;
    average_bal = 0.0;
    bals[7];
}

Student::Student(string name, int age, vector<int> bals)
{
    set_name(name);
    set_age(age);
    set_scores(bals);
}

void Student::set_name(string name)
{
    this->name = name;
    return;
}

string Student::get_name()
{
    return name;
}

void Student::set_age(int age)
{
    this->age = age;
    return;
}

int Student::get_age()
{
    return age;
}

Student::~Student() {};

void Student::set_scores(vector<int> bals)
{
    for (const auto el : bals) {
        this->bals.push_back(el);
    }
    set_bal(this->bals);
    return;
}

vector<int> Student::get_scores()
{
    return bals;
}

void Student::set_bal(vector<int> bals)
{
    int sum = 0;
    for (auto el : bals) {
        sum += el;
    }
    this->average_bal = sum / bals.size();

    return;
}
double Student::get_bal()
{
    return average_bal;
}

bool Student::operator==(const Student& p2)
{
    if (this->average_bal == p2.average_bal)
        return true;
    else
        return false;
}

bool Student::operator!=(const Student& p2)
{
    if (this->average_bal != p2.average_bal)
        return true;
    else
        return false;
}

bool Student::operator<(const Student& pers)
{
    if (this->average_bal < pers.average_bal)
        return true;
    else
        return false;
}

bool Student::operator>=(const Student& pers)
{
    if (this->average_bal >= pers.average_bal)
        return true;
    else
        return false;
}

Student& Student::operator=(const Student& pers)
{
    this->name = pers.name;
    this->age = pers.age;
    this->average_bal = pers.average_bal;
    for (const auto el : pers.bals)
        this->bals.push_back(pers.bals.at(el));

    return *this;
}

ostream& operator<<(ostream& out, const Student& pers)
{
    out << "Name: " << pers.name << endl;
    out << "Age: " << pers.age << endl;
    out << "Average bal: " << pers.average_bal << endl;
    out << "All bals: ";
    for (const auto el : pers.bals) {
        out << el << " ";
    }
    out << endl;

    return out;
}

istream& operator>>(istream& in, Student& pers)
{
    int bal = 0;
    cout << "Enter name: ";
    in >> pers.name;
    cout << "Enter age: ";
    in >> pers.age;
    cout << "Enter bals: ";
    for (int i = 0; i < 7; i++) {
        in >> bal;
        pers.bals.push_back(bal);
    }

    in.ignore();

    return in;
}

ofstream& operator<<(ofstream& out, const Student& pers)
{
    //    out << "Name: ";
    out << pers.name << endl;
    //    out << "Age: ";
    out << pers.age << endl;
    //    out << "Average bal: ";
    out << pers.average_bal << endl;
    //    out << "Bals: ";
    for (const auto el : pers.bals) {
        out << el << " ";
    }
    out << endl;

    return out;
}

ifstream& operator>>(ifstream& in, Student& pers)
{
    int bal = 0;

    in >> pers.name;

    in >> pers.age;

    in >> pers.average_bal;

    for (int i = 0; i < 7; i++) {
        in >> bal;
        pers.bals.push_back(bal);
    }

    in.ignore();

    return in;
}
