/*Polymorphinsm: Ability of object to take on different forms depending of the context in which they're used.
  Types of Polymorphinsm:
    - Compile Time Polym. eg: Constructor, Fn Overloading
    - Run Time Polym. eg: Fn Overriding, Virtual Fns
    
*/

#include<bits/stdc++.h>
using namespace std;

/*
=====================================================
            Compile Time Polymorphism
===================================================== 
*/

// class Student{
//     public:
//         string name;

//         Student()
//         {
//             cout << "No args form" << endl;
//         }

//         Student(string name){
//             this->name = name;
//             cout << "Args form" << endl;
//         }

//         void getInfo(){
//             cout << "Name: " << name << endl;
//         }
// };

// int main() {
//     Student s1;

//     Student s2("Naitik");

//     s2.getInfo();

//     return 0;
// }

/*
=====================================================
            Run Time Polymorphism
===================================================== 
*/

// Fn Overriding is an example of this in which Parent and Child both contain same Fn but with different implementations. The Parent class is stb overridden.

/*
=====================================================
                Example - 1
===================================================== 
*/
// class Parent{
//     public:
//         void getinfo(){
//             cout << "Parent" << endl;
//         }
// };

// class Child : public Parent{
//     public:
//         void getinfo(){
//             cout << "Child" << endl;
//         }
// };

// int main(int argc, char const *argv[])
// {
//     Child c1;
//     c1.getinfo(); // When this is written the Parent's Fn isn't called, Childs' given the priority.

//     return 0;
// }


// =====================================================


/*
=====================================================
                    Virtual
===================================================== 

Virtual Keyword: If a function is marked virtual in a base class, and you override it in a derived class,
then when you call the function through a base class pointer/reference, the derived version is executed (not the base one),
even if the pointer/reference is of base type.
*/
/*
Properties:
    - Dynamic in nature.
    - Defined by the kw "virtual" inside the base class and are always declared with a base class and overridden in a child class.
    - A virtual Fn runs during the run-time.
    
*/
/*
=====================================================
                Example - 1
===================================================== 
*/

#include <iostream>
using namespace std;

class Base {
public:
    // Marked as virtual to allow overriding in derived class
    virtual void sayHello() { // If we remove the "virtual" kw then the O/P changes to "Hello from Base"
        cout << "Hello from Base" << endl;
    }
};

class Derived : public Base {
public:
    // 'override' ensures this function correctly overrides a base class method.
    // If you make a typo or wrong signature, the compiler will catch the error.
    void sayHello() override {
        cout << "Hello from Derived" << endl;
    }
};

int main() {
    Base* ptr = new Derived();  // Base pointer pointing to Derived object
    ptr->sayHello();            // Output: Hello from Derived

    delete ptr;
    return 0;
}

