#include<iostream>
#include<bits/stdc++.h> //This includes each an every library cpp has to offer.
using namespace std;
int main()
{
//  Before using using namespace std;
    // std::cout << "Hello World!" << "\n";
    // std::cout << "Hello World!\n";

//  After using using namespace std;
    cout << "Hello World!" << "\n";
    cout << "Hello World!\n";

    string x;

//    printf("Enter a string: "); // This will also work. The "C" way.
    cout << "Enter a string: ";   // The "C++" way.

    getline(cin, x); //getline(cin, variable_name). Takes input after space too
    cout << "The string is: " << x <<endl;
    return 0;
}