#include<bits/stdc++.h>
using namespace std;

/*
==============================================================================
                            CONSTRUCTORS IN C++
==============================================================================

CONSTRUCTOR: A special member function that is automatically invoked when an object is created.
Primary purpose: Initialize the object's data members and allocate memory.

PROPERTIES OF CONSTRUCTORS:
- Name must be identical to the class name
- No return type (not even void)
- Called automatically only once during object creation
- Memory allocation occurs when constructor is executed
- Must be declared public for external object creation
*/

// Same name as Class.
// No return value.
// Only called ones(automatically), at obj. creation.
// Memo. allocation happens when constructor is c/d.


// ==============================================================================
// EXAMPLE 1: BASIC CONSTRUCTOR WITH DEFAULT INITIALIZATION
// ==============================================================================

// class example{
//     // Make the constuctor public else it'll throw an error ;)
//     public:
//         // Default constructor - automatically called when object is created
//         example()
//         {
//             cout << "Constructor called." << endl;
//         }

//     private:
//         int salary;  // Private member - accessible only within the class

//     public:
//         string name;     // Public members - can be accessed directly
//         string subject;
    
//     // Getter method to access private/public member 'name'
//     string getName(){
//         return name;
//     }

//     // Getter method to access private/public member 'subject'
//     string getSubject(){
//         return subject;
//     }
// };

// int main(){
//     example e1;  // Constructor is automatically invoked here

//     // Setting values to public members after object creation
//     e1.name = "Naitik";
//     e1.subject = "Computer Science";

//     // Accessing members through getter methods
//     cout << e1.getName() << endl;
//     cout << e1.getSubject() << endl;
// }

// --------------------------------------------------

// ==============================================================================
// EXAMPLE 2: CONSTRUCTOR WITH AUTOMATIC DEFAULT VALUE ASSIGNMENT
// ==============================================================================

// class example_two{
//     public:
//         // Constructor that automatically sets default values
//         example_two(){
//             dept = "Computer Science"; // Will create a default department. 
//             cout << "Default dept. is: " << dept << endl;
//         }

//     public:
//         string dept;  // Will be auto-initialized by constructor
//         string name;  // User will set this manually
// };

// int main(){
//     example_two e2;  // Constructor sets dept = "Computer Science" automatically

//     e2.name = "Naitik";  // Manual assignment

//     cout << "The name is: " << e2.name << endl;

//     return 0;
// }

// --------------------------------------------------

/*
==============================================================================
                            TYPES OF CONSTRUCTORS
==============================================================================

C++ supports three main types of constructors:

1. NON-PARAMETERIZED (DEFAULT) CONSTRUCTOR:
   - Takes no arguments
   - Provides default initialization
   - Called automatically when object is created without arguments

2. PARAMETERIZED CONSTRUCTOR:
   - Takes one or more parameters
   - Allows custom initialization during object creation
   - Values are passed during object declaration

3. COPY CONSTRUCTOR:
   - Takes reference to another object of the same class
   - Creates a new object as a copy of existing object
   - Used for object-to-object copying
*/

// ==============================================================================
// NON-PARAMETERIZED CONSTRUCTOR EXAMPLE
// ==============================================================================

// Non-Parameterized
// -----------------

// class example_two{
//     public:
//         // Non-parameterized constructor - no arguments required
//         example_two(){ 
//             dept = "Computer Science"; // Will create a default department. 
//             cout << "Default dept. is: " << dept << endl;
//         }

//     public:
//         string dept;  // Auto-initialized by constructor
//         string name;  // User sets manually
// };

// --------------------------------------------------

// ==============================================================================
// PARAMETERIZED CONSTRUCTOR EXAMPLE
// ==============================================================================

// Parameterized
// -------------

// class Teacher {
//     private:
//         double salary;  // Private member - encapsulated data
    
//     public:
//        // Parameterized constructor - takes 4 arguments for complete initialization
//         Teacher(string n, string d, string s, double sal) {
//             name = n;      // Initialize name with parameter 'n'
//             dept = d;      // Initialize department with parameter 'd'
//             subject = s;   // Initialize subject with parameter 's'
//             salary = sal;  // Initialize salary with parameter 'sal'
//         }
    
//         // Public member variables - accessible from outside
//         string name;
//         string dept;
//         string subject;

//         // Method to modify department after object creation
//         void changeDept(string newDept) {
//             dept = newDept;
//         }
        
//         // Method to display object information
//         void getInfo(){
//             cout << "name: " << name << endl;
//             cout << "subject: " << subject << endl;
//         }
// };

// int main(int argc, char const *argv[])
// {
//     // Object creation with parameterized constructor
//     // All values initialized in single statement
//     Teacher t1("Naitik", "CSE", "C++", 2500000);

//     t1.getInfo();  // Display the initialized values

//     return 0;
// }

// --------------------------------------------------

/*
==============================================================================
                        CONSTRUCTOR OVERLOADING
==============================================================================

CONSTRUCTOR OVERLOADING: A class can have multiple constructors with different
parameter lists (different number or types of parameters).

This is similar to function overloading. The compiler automatically chooses
the appropriate constructor based on the arguments provided during object creation.

Example:
- Teacher() - default constructor
- Teacher(string name) - single parameter constructor  
- Teacher(string name, string dept) - two parameter constructor
- Teacher(string name, string dept, string subject, double salary) - four parameter constructor
*/

// In a single class there can be multiple constructors(differ in type or maybe number of args). This is k/n constructor_overloading 

/*
==============================================================================
                            THE "this" POINTER
==============================================================================

WHAT IS "this" POINTER?
- "this" is a special pointer in C++ that points to the current object
- It holds the address of the object for which the member function is called
- Automatically available in all non-static member functions

WHEN TO USE "this" POINTER?
- When parameter names are same as member variable names
- To resolve naming conflicts between local variables and member variables
- To return reference to current object

SYNTAX:
- this->propertyName is equivalent to (*this).propertyName
- Both access the member variable of the current object
*/

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
//         // PROBLEMATIC APPROACH - naming conflict between parameters and members
//         // Teacher(string name, string dept, string subject, double salary) {
//         //     name = name;     // Ambiguous! Which 'name' is which?
//         //     dept = dept;     // Compiler gets confused
//         //     subject = subject;
//         //     salary = salary;
//         // }

//         // SOLUTION: Use "this" pointer to explicitly refer to member variables
//         Teacher(string name, string dept, string subject, double salary) {
//             this-> name = name;       // this->name = member variable, name = parameter
//             this-> dept = dept;       // Clear distinction between member and parameter
//             this-> subject = subject;
//             this-> salary = salary;
//         }
    
//         // Method to change department
//         void changeDept(string newDept) {
//             dept = newDept;  // No naming conflict, so 'this' not required
//         }
        
//         // Method to display teacher information
//         void getInfo(){
//             cout << "name: " << name << endl;
//             cout << "subject: " << subject << endl;
//         }
// };

// --------------------------------------------------

/*
==============================================================================
                            COPY CONSTRUCTOR
==============================================================================

COPY CONSTRUCTOR: A special constructor that creates a new object as a copy of an existing object.

CHARACTERISTICS:
- Takes a reference to another object of the same class as parameter
- Used to initialize an object with another object of the same class
- If not defined, compiler provides a default copy constructor (shallow copy)
- Syntax: ClassName(ClassName &objectToCopy)

WHEN IS COPY CONSTRUCTOR CALLED?
1. When an object is initialized with another object: Object obj2(obj1);
2. When an object is passed by value to a function
3. When an object is returned by value from a function
*/

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
//         // Parameterized constructor for initial object creation
//        Teacher(string name, string dept, string subject, double salary) {
//             this-> name = name; 
//             this-> dept = dept;
//             this-> subject = subject;
//             this-> salary = salary;
//         }

//         // Method to display teacher information
//         void getInfo(){
//             cout << "name: " << name << endl;
//             cout << "subject: " << subject << endl;
//         }

//         // Custom copy constructor - takes reference to another Teacher object
//         Teacher(Teacher &obj){
//             cout << "Copy constructor invoked." << endl;
//             // Copy all members from the source object to current object
//             this-> name = obj.name; 
//             this-> dept = obj.dept;
//             this-> subject = obj.subject;
//             this-> salary = obj.salary;
//         }
// };

// int main()
// {
//     // Create original object using parameterized constructor
//     Teacher t1("Naitik", "CSE", "C++", 40000.00);

//     // Create copy object using copy constructor
//     Teacher t2(t1);  // This statement invokes the copy constructor

//     t2.getInfo();  // Display copied object's information

//     return 0;
// }

/*
==============================================================================
                        SHALLOW COPY vs DEEP COPY
==============================================================================

SHALLOW COPY:
- Copies all member variable values from source object to destination object
- For pointer members, only the pointer address is copied (not the actual data)
- Both objects end up pointing to the same memory location
- Problem: Modifying data through one object affects the other object

DEEP COPY:  
- Copies member values AND creates separate copies of dynamically allocated memory
- Each object gets its own independent copy of the pointed data
- Changes to one object don't affect the other object
- Required when class contains pointer members or dynamic memory allocation
*/

// There are two types of copies:
    // Shallow Copy
        // A shallow cpy. of an obj. cpys. all of the member values from one obj. to another.
    // Deep Copy
        // A deep cpy, on the other hand, not only cpys. the member values but also make cpys. of any dynamically allocated memo. that the member point to.

/*
==============================================================================
                    SHALLOW COPY EXAMPLE (PROBLEMATIC)
==============================================================================

The following Student class demonstrates SHALLOW COPY problem:
- Both objects will point to the same memory location for cgpaPtr
- When destructor is called, same memory gets deleted twice (undefined behavior)
- Changing CGPA through one object affects the other object
*/
#include <bits/stdc++.h>
using namespace std;

/*
===================================================
            Example - 1 Simpler One
===================================================
*/

#include <iostream>
using namespace std;

// Class with SHALLOW COPY (problematic)
class ShallowCopy {
public:
    int* data;
    
    ShallowCopy(int value) {
        data = new int(value);
        cout << "Created object with value: " << *data << endl;
    }
    
    // Default copy constructor does shallow copy
    // ShallowCopy(const ShallowCopy& other) { data = other.data; }
    
    ~ShallowCopy() {
        cout << "Deleting value: " << *data << endl;
        delete data;
    }
    
    void display() {
        cout << "Value: " << *data << ", Address: " << data << endl;
    }
};

// Class with DEEP COPY (safe)
class DeepCopy {
public:
    int* data;
    
    DeepCopy(int value) {
        data = new int(value);
        cout << "Created object with value: " << *data << endl;
    }
    
    // Custom copy constructor - DEEP COPY
    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data);  // Create NEW memory and copy value
        cout << "Deep copied value: " << *data << endl;
    }
    
    ~DeepCopy() {
        cout << "Deleting value: " << *data << endl;
        delete data;
    }
    
    void display() {
        cout << "Value: " << *data << ", Address: " << data << endl;
    }
};

int main() {
    cout << "=== SHALLOW COPY PROBLEM ===" << endl;
    {
        ShallowCopy obj1(10);
        obj1.display();
        
        ShallowCopy obj2 = obj1;  // Shallow copy!
        obj2.display();
        
        cout << "Both point to SAME memory!" << endl;
        // When this block ends, BOTH destructors try to delete same memory = CRASH!
    }
    
    cout << "\n=== DEEP COPY SOLUTION ===" << endl;
    {
        DeepCopy obj1(20);
        obj1.display();
        
        DeepCopy obj2 = obj1;  // Deep copy!
        obj2.display();
        
        cout << "Each has its OWN memory - Safe!" << endl;
        
        *obj1.data = 99;  // Change obj1
        cout << "After changing obj1:" << endl;
        obj1.display();
        obj2.display();  // obj2 unchanged!
    }
    
    return 0;
}

/*
SIMPLE EXPLANATION:

SHALLOW COPY:
- Copies the pointer address
- Both objects point to SAME memory
- Deleting one affects the other = CRASH

DEEP COPY:  
- Creates NEW memory
- Copies the actual VALUE
- Each object independent = SAFE

RULE: If your class has pointers, write a copy constructor!
*/









/*
===================================================
            Example - 2 A little Complex
===================================================
*/

class ShallowCopyExample {
private:
    char* data;
    int size;

public:
    // Constructor
    ShallowCopyExample(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
        cout << "Constructor: Created object with data: " << data << endl;
    }

    // Default copy constructor (performs shallow copy)
    // This is automatically generated by compiler if not explicitly defined
    // It copies member variables directly without deep copying pointer contents

    // Destructor
    ~ShallowCopyExample() {
        cout << "Destructor: Deleting data: " << data << endl;
        delete[] data;
    }

    // Display function
    void display() const {
        cout << "Data: " << data << ", Address: " << (void*)data << endl;
    }

    // Modify data
    void modifyData(const char* newData) {
        delete[] data;
        size = strlen(newData);
        data = new char[size + 1];
        strcpy(data, newData);
    }
};

class DeepCopyExample {
private:
    char* data;
    int size;

public:
    // Constructor
    DeepCopyExample(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
        cout << "Constructor: Created object with data: " << data << endl;
    }

    // Custom copy constructor (performs deep copy)
    DeepCopyExample(const DeepCopyExample& other) {
        size = other.size;
        data = new char[size + 1];  // Allocate new memory
        strcpy(data, other.data);   // Copy the actual data
        cout << "Copy Constructor: Deep copied data: " << data << endl;
    }

    // Assignment operator (deep copy)
    DeepCopyExample& operator=(const DeepCopyExample& other) {
        if (this != &other) {  // Self-assignment check
            delete[] data;     // Free existing memory
            
            size = other.size;
            data = new char[size + 1];  // Allocate new memory
            strcpy(data, other.data);   // Copy the actual data
            cout << "Assignment Operator: Deep copied data: " << data << endl;
        }
        return *this;
    }

    // Destructor
    ~DeepCopyExample() {
        cout << "Destructor: Deleting data: " << data << endl;
        delete[] data;
    }

    // Display function
    void display() const {
        cout << "Data: " << data << ", Address: " << (void*)data << endl;
    }

    // Modify data
    void modifyData(const char* newData) {
        delete[] data;
        size = strlen(newData);
        data = new char[size + 1];
        strcpy(data, newData);
    }
};

int main() {
    cout << "=== SHALLOW COPY DEMONSTRATION ===" << endl;
    
    {
        ShallowCopyExample obj1("Hello");
        obj1.display();
        
        // Shallow copy - both objects share the same memory
        ShallowCopyExample obj2 = obj1;  // Copy constructor called
        obj2.display();
        
        cout << "Notice: Both objects point to the same memory address!" << endl;
        
        // This will cause problems when destructors are called
        // Both objects will try to delete the same memory location
        cout << "When scope ends, both destructors will try to delete same memory..." << endl;
    }
    // CRASH or undefined behavior occurs here due to double deletion
    
    cout << "\n=== DEEP COPY DEMONSTRATION ===" << endl;
    
    {
        DeepCopyExample obj1("World");
        obj1.display();
        
        // Deep copy - each object has its own memory
        DeepCopyExample obj2 = obj1;  // Copy constructor called
        obj2.display();
        
        cout << "Notice: Objects have different memory addresses!" << endl;
        
        // Modify one object
        obj1.modifyData("Modified");
        cout << "After modifying obj1:" << endl;
        cout << "obj1: ";
        obj1.display();
        cout << "obj2: ";
        obj2.display();
        
        cout << "obj2 remains unchanged - they are truly independent!" << endl;
        
        // Assignment operator test
        DeepCopyExample obj3("Test");
        obj3 = obj1;  // Assignment operator called
        cout << "After assignment (obj3 = obj1):" << endl;
        obj3.display();
    }
    // Safe destruction - each object deletes its own memory
    
    return 0;
}

/*
KEY DIFFERENCES:

SHALLOW COPY:
- Copies member variables directly
- For pointers, only the address is copied (not the data)
- Multiple objects share the same memory location
- Leads to problems: double deletion, dangling pointers
- Default behavior of compiler-generated copy constructor

DEEP COPY:
- Creates new memory for pointer members
- Copies the actual data, not just addresses
- Each object has independent memory
- Safe destruction and modification
- Must be explicitly implemented

WHEN TO USE DEEP COPY:
- When your class manages dynamic memory (pointers)
- When you want true independence between copied objects
- Following the Rule of Three/Five in C++

RULE OF THREE:
If a class needs a custom destructor, it probably needs:
1. Custom destructor
2. Custom copy constructor
3. Custom assignment operator
*/
