#include<bits/stdc++.h>
using namespace std;

// class First_Class{
//     // private: //Access Specifier, by default in c++ it's private.
//     public: // Grants Access to the class to everyone.
//     // protected: // Will learn later.

//         string name; // Attributes / Properties

//         // This is known as a "member function" in c++
//         void printname(string name){
//             cout << "Hello!! " << name;
//         }
// };

// int main()
// {
//     First_Class f1;
//     f1.name = "Naitik";
//     cout << f1.name << endl;
//     f1.printname(f1.name); // Calling the function made in the class.
//     return 0;
// }

// class Second_Class{
//     private:
//         int uid; // Pvt. attribute which can only be accessed by selectives
//     public:
//         string name; 

// };

// int main()
// {
//     Second_Class s2;
//     f1.name = "Naitik";
//     cout << f1.name << endl;
//     // cout << f1.uid << endl; // Gives an error since uid is now a pvt. attribute.
//     return 0;
// }

class Teacher{
    private:
        double salary;
    
    public:
        string name;
        string dept;
        string subject;

    // Setter Fn
    void setDept(string newDept){
        dept = newDept;
    }

    // Setter Fn
    void setSalary(double new_salary){
        salary = new_salary;
    }

    // Getter Fn
    double getSalary(){
        return salary;
    }

    // Getter Fn
    string getDepartment(){
        return dept;
    }
};

int main(){
    Teacher t1;

    t1.name = "Naitik";
    t1.subject = "Computer Science";

    t1.setDept("DevOps");
    t1.setSalary(200000.00);

    cout << "Name: " << t1.name << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Department: " << t1.getDepartment() << endl;
    cout << "Salary: " << t1.getSalary() << "$" << endl;
}