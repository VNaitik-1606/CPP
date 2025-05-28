#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cout << "Enter a number: ";
    cin >> a;
    if (a >= 18)
    {
        cout << "Your'e an adult!\n";
    }else if(a < 18){
        cout << "Your'e not an adult.\n";
    }else{
        cout << "Something went wrong.\n";
    }

    return 0;
}
