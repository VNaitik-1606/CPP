#include<bits/stdc++.h>
using namespace std;

/*
DESTRUCTOR: If a memory is allocated dynamically then it has to be de-allocated dynamically too (by using the "delete" keyword), which can't be done by the default destructor provided by the compiler.

PROPERTIES:
- Same name as the class.
- 

*/
class DestructorExample{
    public:
        string name;
        double *cgpaPtr;

        Student(string name, double cgpa){
            this->name = name;
            cgpaPtr = new double;
            *cgpaPtr = cgpa;
        }

        // DESTRUCTOR

        ~Student(){
            cout << "Destructor invoked" << endl;
        }
};

int main() {

    return 0;
}
