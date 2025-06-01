#include<bits/stdc++.h>
using namespace std;

/*
Abstraction - Hiding all the unnecessary details & showing only the important parts. By using access modifiers or abstract kw.
    Access Modifiers:
        - Public
        - Private
        - Protected

    Abstract Classes: 
        - Used to provide a base class from which other classes can be derived.
        - They can't be instatiated(no objects can be created, instance means objects) and are meant to be inherited.
        - Usually used to define an blueprint for derived class.
*/

class Shape{
    // This line says that any class derived from this class has to have a Fn c/d draw().
    virtual void draw() = 0; // Since it's value is assigned it's k/n pure virtual Fn. So it becomes an abstract class Auto.m

};

class Pentagon : public Shape{
    public:
        void draw(){
            cout << "Pentagon" << endl;
        }
};

int main()
{
    Pentagon p1;
    p1.draw();
    return 0;
}