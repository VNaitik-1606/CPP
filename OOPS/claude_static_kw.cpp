#include <iostream>
using namespace std;

// ===== 1. STATIC VARIABLES IN FUNCTIONS =====
// Static variables retain their value between function calls
// They are initialized only once, even if function is called multiple times

void countFunctionCalls() {
    static int callCount = 0;  // Initialized only once, retains value
    int normalVar = 0;         // Re-initialized every function call
    
    callCount++;    // Increment static variable
    normalVar++;    // This will always be 1
    
    cout << "Function called " << callCount << " times" << endl;
    cout << "Normal variable value: " << normalVar << endl << endl;
}

void demonstrateStaticLifetime() {
    static int staticVar = 100;  // Lives throughout program execution
    cout << "Static variable in function: " << staticVar++ << endl;
}

// ===== 2. STATIC CLASS MEMBERS =====
// Static members belong to the class, not to any specific object
// Shared among all objects of the class

class Student {
private:
    string name;
    int rollNo;
    static int totalStudents;      // Static member variable (declaration)
    static int nextRollNumber;     // Used to auto-assign roll numbers
    
public:
    // Constructor
    Student(string n) : name(n) {
        rollNo = nextRollNumber++;  // Assign and increment
        totalStudents++;            // Increment total count
        cout << "Student " << name << " created with roll no: " << rollNo << endl;
    }
    
    // Destructor
    ~Student() {
        totalStudents--;
        cout << "Student " << name << " destroyed" << endl;
    }
    
    // Static member function
    static int getTotalStudents() {
        // Static functions can only access static members
        // Cannot access non-static members like 'name' or 'rollNo'
        return totalStudents;
    }
    
    static void resetCounter() {
        totalStudents = 0;
        nextRollNumber = 1;
        cout << "Student counters reset!" << endl;
    }
    
    // Regular member function
    void displayInfo() {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
        cout << "Total students in class: " << totalStudents << endl;
    }
    
    // Static function to get next roll number
    static int getNextRollNumber() {
        return nextRollNumber;
    }
};

// Static member variable definition (must be done outside class)
int Student::totalStudents = 0;
int Student::nextRollNumber = 1;

// ===== 3. STATIC OBJECTS =====
// Objects declared as static have extended lifetime

class Counter {
private:
    int count;
    string name;
    
public:
    Counter(string n) : name(n), count(0) {
        cout << "Counter '" << name << "' created" << endl;
    }
    
    ~Counter() {
        cout << "Counter '" << name << "' destroyed with final count: " << count << endl;
    }
    
    void increment() {
        count++;
        cout << name << " count: " << count << endl;
    }
    
    int getCount() const {
        return count;
    }
};

void demonstrateStaticObjects() {
    cout << "=== Inside demonstrateStaticObjects function ===" << endl;
    
    static Counter staticCounter("Static");      // Created only once
    Counter normalCounter("Normal");             // Created every time function is called
    
    staticCounter.increment();
    normalCounter.increment();
    
    cout << "=== Leaving demonstrateStaticObjects function ===" << endl;
    // normalCounter is destroyed here
    // staticCounter remains alive until program ends
}

// ===== 4. STATIC IN GLOBAL SCOPE =====
// Static global variables/functions have internal linkage (file scope only)

static int fileStaticVar = 999;  // Only accessible in this file

static void fileStaticFunction() {
    cout << "This is a file-static function. Value: " << fileStaticVar << endl;
}

// ===== 5. PRACTICAL EXAMPLE - SINGLETON PATTERN =====
// Using static to implement Singleton pattern

class DatabaseConnection {
private:
    string connectionString;
    
    // Private constructor to prevent direct instantiation
    DatabaseConnection(string conn) : connectionString(conn) {
        cout << "Database connection established: " << connectionString << endl;
    }
    
public:
    // Static method to get the single instance
    static DatabaseConnection& getInstance() {
        static DatabaseConnection instance("localhost:3306/mydb");  // Created only once
        return instance;
    }
    
    void query(string sql) {
        cout << "Executing query: " << sql << " on " << connectionString << endl;
    }
    
    // Prevent copying
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
};

// ===== 6. STATIC CONST MEMBERS =====
class MathConstants {
public:
    static const double PI;           // Declaration
    static const int MAX_SIZE = 100;  // Can be initialized here for integral types
    
    static double getCircleArea(double radius) {
        return PI * radius * radius;
    }
};

// Definition of static const member (for non-integral types)
const double MathConstants::PI = 3.14159;

int main() {
    cout << "========== STATIC VARIABLES IN FUNCTIONS ==========" << endl;
    
    // Call function multiple times to see static variable behavior
    countFunctionCalls();  // callCount = 1
    countFunctionCalls();  // callCount = 2  
    countFunctionCalls();  // callCount = 3
    
    demonstrateStaticLifetime();  // staticVar = 100
    demonstrateStaticLifetime();  // staticVar = 101
    demonstrateStaticLifetime();  // staticVar = 102
    
    cout << "========== STATIC CLASS MEMBERS ==========" << endl;
    
    cout << "Initial student count: " << Student::getTotalStudents() << endl;
    cout << "Next roll number will be: " << Student::getNextRollNumber() << endl << endl;
    
    // Create some students
    Student s1("Alice");
    Student s2("Bob");
    
    cout << "\nAfter creating 2 students:" << endl;
    cout << "Total students: " << Student::getTotalStudents() << endl;
    s1.displayInfo();
    s2.displayInfo();
    
    {
        Student s3("Charlie");  // Local scope
        cout << "\nAfter creating Charlie:" << endl;
        cout << "Total students: " << Student::getTotalStudents() << endl;
    }  // s3 destroyed here
    
    cout << "\nAfter Charlie goes out of scope:" << endl;
    cout << "Total students: " << Student::getTotalStudents() << endl;
    
    cout << "\n========== STATIC OBJECTS ==========" << endl;
    
    cout << "Calling demonstrateStaticObjects() first time:" << endl;
    demonstrateStaticObjects();
    
    cout << "\nCalling demonstrateStaticObjects() second time:" << endl;
    demonstrateStaticObjects();
    
    cout << "\nCalling demonstrateStaticObjects() third time:" << endl;
    demonstrateStaticObjects();
    
    cout << "\n========== FILE STATIC VARIABLES/FUNCTIONS ==========" << endl;
    
    cout << "File static variable: " << fileStaticVar << endl;
    fileStaticFunction();
    
    cout << "\n========== SINGLETON PATTERN WITH STATIC ==========" << endl;
    
    // Get database connection instance (created only once)
    DatabaseConnection& db1 = DatabaseConnection::getInstance();
    DatabaseConnection& db2 = DatabaseConnection::getInstance();  // Same instance
    
    db1.query("SELECT * FROM users");
    db2.query("INSERT INTO products VALUES (...)");
    
    cout << "db1 and db2 are same instance: " << (&db1 == &db2 ? "Yes" : "No") << endl;
    
    cout << "\n========== STATIC CONST MEMBERS ==========" << endl;
    
    cout << "PI value: " << MathConstants::PI << endl;
    cout << "MAX_SIZE: " << MathConstants::MAX_SIZE << endl;
    cout << "Area of circle with radius 5: " << MathConstants::getCircleArea(5.0) << endl;
    
    cout << "\n========== PROGRAM ENDING ==========" << endl;
    cout << "Watch the destruction order of static objects..." << endl;
    
    return 0;
}

/*
STATIC KEYWORD SUMMARY:

1. STATIC VARIABLES IN FUNCTIONS:
   - Initialized only once (first function call)
   - Retain value between function calls
   - Live until program ends
   - Default initialized to 0

2. STATIC CLASS MEMBERS:
   - Belong to class, not to any specific object
   - Shared among all objects of the class
   - Must be defined outside class (except integral const)
   - Can be accessed using ClassName::memberName

3. STATIC MEMBER FUNCTIONS:
   - Can be called without creating object
   - Can only access static members
   - Cannot access non-static members or 'this' pointer
   - Called using ClassName::functionName()

4. STATIC OBJECTS:
   - Created only once (even in loops/function calls)
   - Live until program ends
   - Destroyed in reverse order of creation
   - Useful for Singleton pattern

5. STATIC GLOBAL SCOPE:
   - Internal linkage (file scope only)
   - Not visible to other files
   - Alternative to unnamed namespaces

MEMORY ALLOCATION:
- Static variables stored in data segment
- Not on stack or heap
- Zero-initialized by default
- Live for entire program duration

USES:
- Counters that persist between function calls
- Shared data among class instances  
- Singleton pattern implementation
- File-local variables/functions
- Constants that belong to class rather than objects
*/