#include<bits/stdc++.h>
using namespace std;

// Example 1: Simple class WITHOUT destructor
class SimpleStudent {
private:
    string name;
    int age;
    
public:
    // Constructor
    SimpleStudent(string n, int a) {
        name = n;
        age = a;
        cout << "Constructor: Created student " << name << endl;
    }
    
    // No destructor defined - compiler provides default one
    // Default destructor automatically cleans up simple data types
    
    void display() {
        cout << "Student: " << name << ", Age: " << age << endl;
    }
};

// Example 2: Class WITH custom destructor (needed for dynamic memory)
class StudentWithArray {
private:
    char* name;        // Pointer to dynamically allocated memory
    int* grades;       // Array of grades
    int numGrades;
    
public:
    // Constructor - allocates memory
    StudentWithArray(const char* n, int gradeCount) {
        // Allocate memory for name
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        
        // Allocate memory for grades array
        numGrades = gradeCount;
        grades = new int[numGrades];
        
        // Initialize grades to 0
        for(int i = 0; i < numGrades; i++) {
            grades[i] = 0;
        }
        
        cout << "Constructor: Created " << name << " with " << numGrades << " grades" << endl;
    }
    
    // CUSTOM DESTRUCTOR - cleans up dynamic memory
    ~StudentWithArray() {
        cout << "Destructor: Cleaning up " << name << "'s data" << endl;
        
        // Free dynamically allocated memory
        delete[] name;     // Delete name array
        delete[] grades;   // Delete grades array
        
        cout << "Destructor: Memory freed for " << name << endl;
    }
    
    void setGrade(int index, int grade) {
        if(index >= 0 && index < numGrades) {
            grades[index] = grade;
        }
    }
    
    void display() {
        cout << "Student: " << name << ", Grades: ";
        for(int i = 0; i < numGrades; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }
};

// Example 3: Class demonstrating destructor call order
class NumberCounter {
private:
    int number;
    static int totalObjects;  // Count total objects created
    
public:
    // Constructor
    NumberCounter(int n) {
        number = n;
        totalObjects++;
        cout << "Constructor: Created object #" << number 
             << " (Total objects: " << totalObjects << ")" << endl;
    }
    
    // Destructor
    ~NumberCounter() {
        cout << "Destructor: Destroying object #" << number 
             << " (Remaining objects: " << totalObjects - 1 << ")" << endl;
        totalObjects--;
    }
    
    void display() {
        cout << "Object number: " << number << endl;
    }
    
    static int getTotalObjects() {
        return totalObjects;
    }
};

// Initialize static variable
int NumberCounter::totalObjects = 0;

// Example 4: Resource management class
class FileManager {
private:
    string filename;
    bool isOpen;
    
public:
    // Constructor - opens a "file" (simulated)
    FileManager(string fname) {
        filename = fname;
        isOpen = true;
        cout << "Constructor: Opened file '" << filename << "'" << endl;
    }
    
    // Destructor - closes the "file" (simulated)
    ~FileManager() {
        if(isOpen) {
            cout << "Destructor: Closing file '" << filename << "'" << endl;
            isOpen = false;
        }
    }
    
    void writeData(string data) {
        if(isOpen) {
            cout << "Writing to " << filename << ": " << data << endl;
        }
    }
    
    void closeFile() {
        if(isOpen) {
            cout << "Manually closing file '" << filename << "'" << endl;
            isOpen = false;
        }
    }
};

// Function to demonstrate automatic destructor calls
void demonstrateScope() {
    cout << "\n=== DEMONSTRATING SCOPE AND DESTRUCTORS ===" << endl;
    
    cout << "Entering function scope..." << endl;
    
    {
        cout << "Entering inner block..." << endl;
        SimpleStudent s1("Alice", 20);
        StudentWithArray s2("Bob", 3);
        s2.setGrade(0, 85);
        s2.setGrade(1, 90);
        s2.setGrade(2, 78);
        
        s1.display();
        s2.display();
        
        cout << "Leaving inner block - destructors will be called automatically!" << endl;
    }  // s1 and s2 go out of scope here - destructors called automatically
    
    cout << "Back in function scope - objects have been destroyed" << endl;
}

void demonstrateDestructorOrder() {
    cout << "\n=== DEMONSTRATING DESTRUCTOR CALL ORDER ===" << endl;
    
    cout << "Creating objects in order..." << endl;
    NumberCounter obj1(1);
    NumberCounter obj2(2);
    NumberCounter obj3(3);
    
    cout << "\nAll objects created. Total: " << NumberCounter::getTotalObjects() << endl;
    cout << "When function ends, destructors will be called in REVERSE order!" << endl;
    
    // Objects will be destroyed in reverse order: obj3, obj2, obj1
}

void demonstrateResourceManagement() {
    cout << "\n=== DEMONSTRATING RESOURCE MANAGEMENT ===" << endl;
    
    {
        FileManager file1("document.txt");
        FileManager file2("data.csv");
        
        file1.writeData("Hello World");
        file2.writeData("Name,Age\nJohn,25");
        
        cout << "Files are open and being used..." << endl;
        
        // We don't need to manually close files
        // Destructors will automatically close them when objects go out of scope
        
    }  // Destructors automatically close files here
    
    cout << "Files automatically closed by destructors!" << endl;
}

int main() {
    cout << "DESTRUCTOR DEMONSTRATION" << endl;
    cout << "========================" << endl;
    
    // Example 1: Simple objects (no custom destructor needed)
    cout << "\n=== SIMPLE OBJECTS ===" << endl;
    {
        SimpleStudent student("John", 22);
        student.display();
        cout << "End of scope - default destructor will clean up automatically" << endl;
    }  // Default destructor called here
    
    // Example 2: Objects with dynamic memory (custom destructor needed)
    cout << "\n=== OBJECTS WITH DYNAMIC MEMORY ===" << endl;
    {
        StudentWithArray student("Mary", 4);
        student.setGrade(0, 95);
        student.setGrade(1, 87);
        student.setGrade(2, 92);
        student.setGrade(3, 88);
        student.display();
        cout << "End of scope - custom destructor will free memory" << endl;
    }  // Custom destructor called here - frees allocated memory
    
    // Demonstrate scope and automatic cleanup
    demonstrateScope();
    
    // Demonstrate destructor call order
    demonstrateDestructorOrder();
    
    // Demonstrate resource management
    demonstrateResourceManagement();
    
    cout << "\n=== KEY POINTS ABOUT DESTRUCTORS ===" << endl;
    cout << "1. Called automatically when object goes out of scope" << endl;
    cout << "2. Called in REVERSE order of construction" << endl;
    cout << "3. Used to free resources (memory, files, etc.)" << endl;
    cout << "4. Name: ~ClassName() - tilde (~) followed by class name" << endl;
    cout << "5. No parameters, no return type" << endl;
    cout << "6. If you use 'new', you need custom destructor with 'delete'" << endl;
    
    return 0;
}