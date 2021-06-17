#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    int age;
    double average_bal;
    vector<int> bals;

public:
    Student();
    Student(string, int, vector<int>);
    ~Student();
    void set_name(string);
    string get_name();
    void set_age(int);
    int get_age();
    void set_bal(vector<int>);
    double get_bal();
    void set_scores(vector<int>);
    vector<int> get_scores();

    bool operator==(const Student&);
    bool operator!=(const Student&);
    bool operator<(const Student&);
    bool operator>=(const Student&);

    Student& operator=(const Student& pers);

    friend ostream& operator<<(ostream& out, const Student& pers);

    friend istream& operator>>(istream& in, Student& pers);

    friend ofstream& operator<<(ofstream& out, const Student& pers);

    friend ifstream& operator>>(ifstream& in, Student& pers);
};

#endif // STUDENT_H
