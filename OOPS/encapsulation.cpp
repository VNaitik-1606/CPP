// Encapsulation is wrapping of data and member Fns in a single unit called "class".
// In other words attributes + member Fns = Class
// Useful in data hiding.

#include<bits/stdc++.h>
using namespace std;

class Account{
    private:
        double balance; // Data Hidden
        string password; // Data Hidden
    public:
        string accountId;
        string userName;
};
