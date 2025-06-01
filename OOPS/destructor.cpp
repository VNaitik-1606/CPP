#include<bits/stdc++.h>
using namespace std;

/*
DESTRUCTOR: If a memory is allocated dynamically then it has to be de-allocated dynamically too (by using the "delete" keyword), which can't be done by the default destructor provided by the compiler.

PROPERTIES:
- Same name as the class.
- 

*/
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    ~Student() {
        cout << "Destructor invoked" << endl;
        delete cgpaPtr;
        cgpaPtr = nullptr;  // Good practice
    }
    
    void getInfo(){
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("Naitik Verma", 8.9);
    s1.getInfo();
    return 0;
}
