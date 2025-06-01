// Inheritance - One of the four pillars of OOPS, It means when properties & member Fns of base/parent class are passed on to the derived/child class.
// Advantages
//  - Code reuse-ability  

/*
=====================================================
                 Example - 1
=====================================================
*/

#include<bits/stdc++.h>
using namespace std;

// class Person{
//     public:
//         string name;
//         int age;

//         Person(string name, int age){
//             this->name = name;
//             this->age = age;
//         }
//         Person(){
//             cout << "Parent Constructor" << endl;
//         }

//         ~Person(){
//             cout << "Parent Destructor" << endl;
//         }
// };

// /*   
// Child Class Syntax: 
// -------------------

// class ChildClassName : AcessModifier ParentClass

// */ 

// class Student : public Person{
//     public: 
//         int rno;

//         void getInfo(){

//             cout << "Name: " << name << endl;
//             cout << "Age: " << age << endl;
//             cout << "Rno: " << rno << endl;
//         }

//         Student(){
//             cout << "Child constructor" << endl;
//         }

//         ~Student(){
//             cout << "Child Destructor" << endl;
//         }
// };

// int main() {
//     Student s1;
//     s1.name = "Naitik";
//     s1.age = 18;
//     s1.rno = 47;

//     s1.getInfo();
//     return 0;
// }

/*
=====================================================
                 Example - 2
=====================================================
*/

// class Person{
//     public:
//         string name;
//         int age;

//         Person(string name, int age){
//             this->name = name;
//             this->age = age;
//         }
//         Person(){
//             cout << "Parent Constructor" << endl;
//         }

//         ~Person(){
//             cout << "Parent Destructor" << endl;
//         }
// };


// class Student : public Person{
//     public: 
//         int rno;

//         Student(string name, int age, int rno) : Person(name, age){
//             this->rno = rno;
//             cout << "Child constructor" << endl;
//         }

//         Student(){
//             cout << "Default Constructor" << endl;
//         }

//         void getInfo(){

//             cout << "Name: " << name << endl;
//             cout << "Age: " << age << endl;
//             cout << "Rno: " << rno << endl;
//         }

//         ~Student(){
//             cout << "Child Destructor" << endl;
//         }

// };

// int main() {
//     Student s1("Alice",20,101);
//     // s1.name = "Naitik";
//     // s1.age = 18;
//     // s1.rno = 47;

//     s1.getInfo();
//     return 0;
// }

/*
=====================================================
                Types of Inheritence
===================================================== 
*/

#include <iostream>
using namespace std;

// ===== 1. SINGLE INHERITANCE =====
// One child class inherits from one parent class

class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n, int a) : name(n), age(a) {
        cout << "Animal constructor called" << endl;
    }
    
    void eat() {
        cout << name << " is eating" << endl;
    }
    
    void sleep() {
        cout << name << " is sleeping" << endl;
    }
};

// Dog inherits from Animal (Single Inheritance)
class Dog : public Animal {
private:
    string breed;
    
public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {
        cout << "Dog constructor called" << endl;
    }
    
    void bark() {
        cout << name << " is barking: Woof!" << endl;
    }
    
    void showInfo() {
        cout << "Dog: " << name << ", Age: " << age << ", Breed: " << breed << endl;
    }
};

// ===== 2. MULTILEVEL INHERITANCE =====
// Chain of inheritance: A -> B -> C

// Puppy inherits from Dog, which inherits from Animal
class Puppy : public Dog {
private:
    bool isVaccinated;
    
public:
    Puppy(string n, int a, string b, bool vaccinated) 
        : Dog(n, a, b), isVaccinated(vaccinated) {
        cout << "Puppy constructor called" << endl;
    }
    
    void play() {
        cout << name << " is playing like a puppy!" << endl;
    }
    
    void showPuppyInfo() {
        showInfo();  // From Dog class
        cout << "Vaccination status: " << (isVaccinated ? "Yes" : "No") << endl;
    }
};

// ===== 3. MULTIPLE INHERITANCE =====
// One child class inherits from multiple parent classes

class Mammal {
protected:
    bool warmBlooded;
    
public:
    Mammal() : warmBlooded(true) {
        cout << "Mammal constructor called" << endl;
    }
    
    void breathe() {
        cout << "Breathing with lungs" << endl;
    }
};

class Carnivore {
protected:
    string diet;
    
public:
    Carnivore() : diet("meat") {
        cout << "Carnivore constructor called" << endl;
    }
    
    void hunt() {
        cout << "Hunting for " << diet << endl;
    }
};

// Lion inherits from both Mammal and Carnivore (Multiple Inheritance)
class Lion : public Mammal, public Carnivore {
private:
    string maneColor;
    
public:
    Lion(string color) : maneColor(color) {
        cout << "Lion constructor called" << endl;
    }
    
    void roar() {
        cout << "ROARRR! Lion with " << maneColor << " mane" << endl;
    }
    
    void showLionInfo() {
        cout << "Warm-blooded: " << (warmBlooded ? "Yes" : "No") << endl;
        cout << "Diet: " << diet << endl;
        cout << "Mane color: " << maneColor << endl;
    }
};

// ===== 4. HIERARCHICAL INHERITANCE =====
// Multiple child classes inherit from same parent class

class Vehicle {
protected:
    string brand;
    int year;
    
public:
    Vehicle(string b, int y) : brand(b), year(y) {
        cout << "Vehicle constructor called" << endl;
    }
    
    void start() {
        cout << brand << " vehicle is starting" << endl;
    }
    
    void stop() {
        cout << brand << " vehicle is stopping" << endl;
    }
};

// Multiple classes inheriting from Vehicle (Hierarchical Inheritance)
class Car : public Vehicle {
private:
    int doors;
    
public:
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {
        cout << "Car constructor called" << endl;
    }
    
    void drive() {
        cout << brand << " car is driving on road" << endl;
    }
    
    void showCarInfo() {
        cout << "Car: " << brand << " (" << year << "), Doors: " << doors << endl;
    }
};

class Bike : public Vehicle {
private:
    bool hasGears;
    
public:
    Bike(string b, int y, bool gears) : Vehicle(b, y), hasGears(gears) {
        cout << "Bike constructor called" << endl;
    }
    
    void ride() {
        cout << brand << " bike is being ridden" << endl;
    }
    
    void showBikeInfo() {
        cout << "Bike: " << brand << " (" << year << "), Gears: " 
             << (hasGears ? "Yes" : "No") << endl;
    }
};

class Truck : public Vehicle {
private:
    int loadCapacity;
    
public:
    Truck(string b, int y, int capacity) : Vehicle(b, y), loadCapacity(capacity) {
        cout << "Truck constructor called" << endl;
    }
    
    void loadCargo() {
        cout << brand << " truck is loading cargo" << endl;
    }
    
    void showTruckInfo() {
        cout << "Truck: " << brand << " (" << year << ") - Capacity: " 
             << loadCapacity << " tons" << endl;
    }
};

// ===== 5. HYBRID INHERITANCE =====
// Combination of multiple inheritance types

class Engine {
protected:
    int horsepower;
    
public:
    Engine(int hp) : horsepower(hp) {
        cout << "Engine constructor called" << endl;
    }
    
    void engineInfo() {
        cout << "Engine: " << horsepower << " HP" << endl;
    }
};

class SportsCar : public Car, public Engine {
private:
    int topSpeed;
    
public:
    SportsCar(string b, int y, int d, int hp, int speed) 
        : Car(b, y, d), Engine(hp), topSpeed(speed) {
        cout << "SportsCar constructor called" << endl;
    }
    
    void race() {
        cout << brand << " sports car is racing at " << topSpeed << " mph!" << endl;
    }
    
    void showSportsCarInfo() {
        showCarInfo();
        engineInfo();
        cout << "Top Speed: " << topSpeed << " mph" << endl;
    }
};

int main() {
    cout << "========== SINGLE INHERITANCE ===========" << endl;
    Dog myDog("Buddy", 3, "Golden Retriever");
    myDog.eat();      // From Animal
    myDog.bark();     // From Dog
    myDog.showInfo();
    cout << endl;
    
    cout << "========== MULTILEVEL INHERITANCE =========" << endl;
    Puppy myPuppy("Max", 1, "Labrador", true);
    myPuppy.eat();             // From Animal (grandparent)
    myPuppy.bark();            // From Dog (parent)
    myPuppy.play();            // From Puppy (self)
    myPuppy.showPuppyInfo();
    cout << endl;
    
    cout << "========== MULTIPLE INHERITANCE ===========" << endl;
    Lion king("Golden");
    king.breathe();        // From Mammal
    king.hunt();           // From Carnivore
    king.roar();           // From Lion
    king.showLionInfo();
    cout << endl;
    
    cout << "========= HIERARCHICAL INHERITANCE ========" << endl;
    Car myCar("Toyota", 2020, 4);
    Bike myBike("Honda", 2019, true);
    Truck myTruck("Ford", 2021, 10);
    
    myCar.start();         // From Vehicle
    myCar.drive();         // From Car
    myCar.showCarInfo();
    
    myBike.start();        // From Vehicle
    myBike.ride();         // From Bike
    myBike.showBikeInfo();
    
    myTruck.start();       // From Vehicle
    myTruck.loadCargo();   // From Truck
    myTruck.showTruckInfo();
    cout << endl;
    
    cout << "============ HYBRID INHERITANCE ===========" << endl;
    SportsCar ferrari("Ferrari", 2022, 2, 800, 200);
    ferrari.start();               // From Vehicle (via Car)
    ferrari.drive();               // From Car
    ferrari.engineInfo();          // From Engine
    ferrari.race();                // From SportsCar
    ferrari.showSportsCarInfo();
    
    return 0;
}

/*
INHERITANCE TYPES SUMMARY:

1. SINGLE INHERITANCE
   - One child inherits from one parent
   - Example: Dog inherits from Animal
   - Simple and straightforward

2. MULTILEVEL INHERITANCE  
   - Chain of inheritance (A->B->C)
   - Example: Animal -> Dog -> Puppy
   - Child has access to all ancestor members

3. MULTIPLE INHERITANCE
   - One child inherits from multiple parents
   - Example: Lion inherits from Mammal AND Carnivore
   - Can cause diamond problem (solved with virtual inheritance)

4. HIERARCHICAL INHERITANCE
   - Multiple children inherit from same parent
   - Example: Car, Bike, Truck all inherit from Vehicle
   - Code reuse and consistent interface

5. HYBRID INHERITANCE
   - Combination of above types
   - Example: SportsCar inherits from Car AND Engine
   - Most complex but powerful

ACCESS SPECIFIERS:
- public: Members accessible everywhere
- protected: Members accessible in class and derived classes
- private: Members accessible only in same class

CONSTRUCTOR ORDER:
- Parent constructors called before child constructors
- In multiple inheritance: left to right order
- Destructors called in reverse order
*/


/*
Takeaways:
    - Parent's Constructor is called firstly then child's.
    - Child's Destructor is called first then parent's.
*/