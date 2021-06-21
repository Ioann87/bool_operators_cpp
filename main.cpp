#include <ctime>
#include <fstream>
#include <iostream>
#include <student.h>
#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));

    vector<string> names;
    string name;

    ifstream file("/home/shastiva/c_projects/homework23/Names");
    while (getline(file, name)) {
        names.push_back(name);
    }
    file.close();
    vector<int> bals;

    vector<Student> students;

    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < 7; i++) {
            bals.push_back((rand() % 20));
        }
        Student obj(names[rand() % 67], rand() % 80 + 15, bals);
        students.push_back(obj);
        bals.clear();
    }

    ofstream new_students;

    new_students.open("/home/shastiva/c_projects/homework23/new_students");
    for (int i = 0; i < 10; i++) {
        new_students << students[i] << endl;
    }
    vector<Student> students_out;

    new_students.close();

    ifstream new_students1("/home/shastiva/c_projects/homework23/new_students");
    
    for (int i = 0; i < 10; i++) {
        Student obj2;
        new_students1 >> obj2;
        students_out.push_back(obj2);
    }

    new_students1.close();

    for (int i = 0; i < 10; i++) {
        cout << students_out.at(i);
    }



    return 0;
}
