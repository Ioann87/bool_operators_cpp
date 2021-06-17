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

    ofstream file;
    file.open("Names.txt");

    while (!file.eof()) {
        file.getline(file, name);
        names.push_back();
    }

    vector<int> bals;

    for (int i = 0; i < 7; i++) {
        bals.push_back((rand() % 20));
    }

    Student obj(name, 33, bals);

    cout << obj;

    return 0;
}
