#include<bits/stdc++.h>
using namespace std;


// Wild Pointers

// int main() {
    // Contains some some random value.
//     int *ptr;
//     return 0;
// }   

// Null Pointers

// int main(int argc, char const *argv[])
// {
//     // Doesn't to any valid memo. location but NULL.
//     int *ptr = NULL;

//     return 0;
// }

// Void Pointers / Generic Pointers

// int main(int argc, char const *argv[])
// {
//     int num = 42;
//     double pi = 3.14159;

//     void* ptr;  // void pointer can point to any data type

//     ptr = &num;  // ptr points to an int
//     cout << "Value of num through void pointer: " << *(int*)ptr << endl;

//     ptr = &pi;   // ptr points to a double
//     cout << "Value of pi through void pointer: " << *(double*)ptr << endl;

//     return 0;
// }

// Dangling Pointer

#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(5);  

    delete ptr; 
    // Now ptr is dangling — it points to freed memory.

    // Accessing *ptr here causes undefined behavior
    cout << *ptr << endl;  // DON'T DO THIS!

    // ptr = nullptr;  // fix: set pointer to nullptr after delete

    // if (ptr == nullptr) {
    //     cout << "Pointer is safely set to nullptr after delete." << endl;
    // }

    return 0;
}
