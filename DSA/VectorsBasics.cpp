#include<iostream>
#include<vector>
using namespace std;

// What are Vectors? 
//  They're same as the arrays except they're dynamic in nature. They're present in vector header file

/*
Types of Decleration of Vector
-------------------------------
    -> vector<int> vec;
    -> vector<int> vec = {1,2,3,4};
    -> vector<int> vec (size, index_with_vals);
*/

// int main() {
    // vector<int> vec; // Created a vector c/d vec with default size 0.

    // vector<int> vec = {1,2,3,4}; // Created a vector c/d vec with default elements and size 4.
    // cout << vec[0] << endl;

    // vector<int> vec(5, 0); // Created a vector with 5 elements where every value is 0.
    // cout << vec[0] << endl;
    // cout << vec[1] << endl;
    // cout << vec[2] << endl;
    // cout << vec[3] << endl;
    // cout << vec[4] << endl;
//     return 0;
// }


// Loops on Vectors aka For Each loop
// ----------------------------------

// int main(int argc, char const *argv[])
// {
//     vector<int> vec = {4,5,6};

//     for (int i : vec) // The type of i has have to be the same as the type of vector here it's "int"
//     {
//         cout << i << endl; // It won't print the index instead it'll print the value at the index.
//     }
    
//     return 0;
// }


// Functions in vectors

/*
-> 1. size() Fn
   ----------
*/

// int main(int argc, char const *argv[])
// {
//     vector<int> vec = {4, 5, 6};

//     cout << "The size of the vector is: " << vec.size() << endl; // To get the size of the vector.

//     return 0;
// }

/*
-> 2. push_back() Fn
   -----------------
*/

// int main(int argc, char const *argv[])
// {
//     vector<int> vec; // If a vector is there then this Fn will insert the elm into the vector, at the zeroth (0) index(no pre-existing elms) or to the last index(if there are pre-existing elms) and after that 0 + 1 or n + 1 and so on.
//     cout << "Size before push_back is: " << vec.size() << endl;

//     vec.push_back(25);
    
//     cout << "Size after push_back is: " << vec.size() << endl;

//     return 0;
// }

/*
-> 3. pop_back() Fn
   -----------------
*/

// int main(int argc, char const *argv[])
// {
//     vector<int> vec;
//     vec.push_back(0);
//     vec.push_back(1);
//     vec.push_back(2);

//     for(int val : vec)
//     {
//         cout << "Vals before popping: " << val << endl;
//     }

//     cout << endl;

//     cout << "Size before popping: " << vec.size() << endl;

//     cout << endl;

//     vec.pop_back(); // By default it removes the last index of the vector.
//     cout << "Size after popping: " << vec.size() << endl;

//     cout << endl;

//     for(int val : vec)
//     {
//         cout << "Vals after popping: " << val << endl;
//     }
//     return 0;
// }

/*
-> 4. front() and back() Fns
   -------------------------
*/

// int main(int argc, char const *argv[])
// {
//     vector<int> vec = {69, 79, 89};

//     cout << vec.front() << endl; // It'll print the first element of the vector.

//     cout << vec.back() << endl; // It'll print the last element of the vector.
    
//     return 0;
// }

/*
-> 5. at() Fn
   ----------
*/

// int main(int argc, char const *argv[])
// {
//     int n;
//     cout << "Enter index to search: ";
//     cin >> n;

//     vector<int> vec = {1, 2, 3, 4, 5};

//     cout << "Value at " << n << " is: " << vec.at(n) << endl;
//     return 0;
// }

// =====================================================

// Verification that when vector is out of storage then it's size is automatically increased and capacity is doubled.

/*
What is the difference between size and capacity?
    -> SIZE - The amt. of elements which are currently present in the vector.
    -> CAPACITY - The amt. of elemets which a vector can hold without reallocating memory.
*/

// int main(int argc, char const *argv[])
// {
//     vector<int> vec(5, 0);

//     cout << "Size before: " << vec.size() << endl;

//     vec.push_back(2);

//     cout << "Size after: " << vec.size() << endl;
    
//     for(int val : vec)
//     {
//         cout << val << endl;
//     }

//     cout << vec.capacity() << endl;

//     return 0;
// }

// Problem - 1 Find the duplicate number.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 1}; 

    int xor_result = 0;
    for (int num : vec) {
        xor_result ^= num; 
    }

    cout << "The duplicate is: " << xor_result << endl; 
    return 0;
}
