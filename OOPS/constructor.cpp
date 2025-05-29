#include<bits/stdc++.h>
using namespace std;

// Special method automatically invoked at time of object creation. Used for initialization.
// Properties:
    // Same name as Class.
    // No return value.
    // Only called ones(automatically), at obj. creation.
    // Memo. allocation happens when constructor is c/d.


// class example{
//     // Make the constuctor public else it'll throw an error ;)
//     public:
//         example()
//         {
//             cout << "Constructor called." << endl;
//         }

//     private:
//         int salary;

//     public:
//         string name;
//         string subject;
    
//     string getName(){
//         return name;
//     }

//     string getSubject(){
//         return subject;
//     }
// };

// int main(){
//     example e1;

//     e1.name = "Naitik";
//     e1.subject = "Computer Science";

//     cout << e1.getName() << endl;
//     cout << e1.getSubject() << endl;
// }

// --------------------------------------------------

// class example_two{
//     public:
//         example_two(){
//             dept = "Computer Science"; // Will create a default department. 
//             cout << "Default dept. is: " << dept << endl;
//         }

//     public:
//         string dept;
//         string name;
// };

// int main(){
//     example_two e2;

//     e2.name = "Naitik";

//     cout << "The name is: " << e2.name << endl;

//     return 0;
// }

// --------------------------------------------------

// Types of constructor:
    // Non-Parameterized 
    // Parameterized 
    // Copy

// --------------------------------------------------

// Non-Parameterized
// -----------------

// class example_two{
//     public:
//         example_two(){ 
//             dept = "Computer Science"; // Will create a default department. 
//             cout << "Default dept. is: " << dept << endl;
//         }

//     public:
//         string dept;
//         string name;
// };

// --------------------------------------------------

// Parameterized
// -------------

// class Teacher {
//     private:
//         double salary;
    
//     public:
//         Teacher(string n, string d, string s, double sal) {
//             name = n;
//             dept = d;
//             subject = s;
//             salary = sal;
//         }
    
//         string name;
//         string dept;
//         string subject;

//         void changeDept(string newDept) {
//             dept = newDept;
//         }
        
//         void getInfo(){
//             cout << "name: " << name << endl;
//             cout << "subject: " << subject << endl;
//         }
// };

// int main(int argc, char const *argv[])
// {
//     Teacher t1("Naitik", "CSE", "C++", 2500000);

//     t1.getInfo();

//     return 0;
// }

// --------------------------------------------------

// In a single class there can be multiple constructors(differ in type or maybe number of args). This is k/n constructor_overloading 

// --------------------------------------------------

// "this->" pointer
// -----------------

// "this" is a special pointer in c++ which points at the current object.
// this-> prop_name is same as *(this).prop_name

// class Teacher {
//     public:
//         string name;
//         string dept;
//         string subject;
//     private:
//         double salary;
    
//     public:
//         // Teacher(string name, string dept, string subject, double salary) {
//         //     name = name; 
//         //     dept = dept;
//         //     subject = subject;
//         //     salary = salary;
//         // }
// //    // Often time the above apporoach can be confusing that what belongs to the object and what are the Constructor's args., So to overcome this, use:
//        Teacher(string name, string dept, string subject, double salary) {
//             this-> name = name; 
//             this-> dept = dept;
//             this-> subject = subject;
//             this-> salary = salary;
//         }
    
//         void changeDept(string newDept) {
//             dept = newDept;
//         }
        
//         void getInfo(){
//             cout << "name: " << name << endl;
//             cout << "subject: " << subject << endl;
//         }
// };

// --------------------------------------------------

// Copy Constructor
// ----------------

// Default special constructor used to copy props. of one object into another.

// Using the Teacher class
// class Teacher {
//     public:
//         string name;
//         string dept;
//         string subject;
//     private:
//         double salary;
    
//     public:
//        Teacher(string name, string dept, string subject, double salary) {
//             this-> name = name; 
//             this-> dept = dept;
//             this-> subject = subject;
//             this-> salary = salary;
//         }

//         void getInfo(){
//             cout << "name: " << name << endl;
//             cout << "subject: " << subject << endl;
//         }

//         // Creating custom copy constructor
//         Teacher(Teacher &obj){
//             cout << "Copy constructor invoked." << endl;
//             this-> name = obj.name; 
//             this-> dept = obj.dept;
//             this-> subject = obj.subject;
//             this-> salary = obj.salary;
//         }
// };

// int main()
// {
//     Teacher t1("Naitik", "CSE", "C++", 40000.00);

//     Teacher t2(t1);

//     t2.getInfo();

//     return 0;
// }

// There are two types of copies:
    // Shallow Copy
        // A shallow cpy. of an obj. cpys. all of the member values from one obj. to another.
    // Deep Copy
        // A deep cpy, on the other hand, not only cpys. the member values but also make cpys. of any dynamically allocated memo. that the member point to.

// class Student{

//     public:
//         string name;
//         double *cgpaPtr;

//         Student(string name, double cgpa){
//             this-> name = name;
//             cgpaPtr = new double;
            // *cgpaPtr = cgpa;
//         }

//         Student(Student &obj) {
//             this->name = obj.name;
//             this->cgpaPtr = obj.cgpaPtr; 
//         }

//         void getInfo(){
//             cout << "name: " << name << endl;
//             cout << "cgpa: " << *cgpaPtr << endl;
//         }
// };

// int main(int argc, char const *argv[])
// {
//     Student s1("rahul kumar", 8.9);

//     Student s2(s1);
//     s2.getInfo();
//     return 0;
// }