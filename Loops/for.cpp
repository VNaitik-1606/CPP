#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;

    cout << "Enter a number: ";
    cin >> n;
    cin.ignore(); //Why? https://chatgpt.com/share/68320a70-fe14-800c-b21b-7b8d7ff5af28

    cout << "Enter a word: ";
    getline(cin, s);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        // Brain Teaser 

        if (i == 5)
        {
            continue;
        }

        if (i == 5)
        {
            break;
        }

        cout << s << '\n';
        
    }

    return 0;
}