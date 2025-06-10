#include<bits/stdc++.h>
using namespace std;

/*
=====================================================
                Pattern - 1
===================================================== 
*/

// int main() {
//     int n;
//     cin >> n;
    // cout << endl;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << "*";
//         }

//         cout << endl;
//     }

//     return 0;
// }

/*
=====================================================
                    Pattern - 2
===================================================== 
*/

// int main(int argc, char const *argv[])
// {
    // char c; // If input is "z" then the output will be!?
    // cin >> c;
// 
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
        // for (int j = 0; j < n; j++)
        // {
            // cout << c << " ";
            // c++;
        // }
        // cout << endl;
    // }
    // 
    // return 0;
// }

/*
=====================================================
                    Pattern - 3
===================================================== 
*/  

// For Stars
// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             cout << '*';
//         }
//         cout << endl;
        
//     }
    
//     return 0;
// }

// =====================================================

// For nums
// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             cout << i + 1 << " "; // Also try for j + 1
//         }
//         cout << endl;    
//     }
    
//     return 0;
// }

/// =====================================================

// For chars
// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;

//     char c;
//     cin >> c;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             cout << c << " ";
//         }
//         c++;
//         cout << endl;    
//     }
    
//     return 0;
// }

/*
=====================================================
                  Pattern - 4
===================================================== 
*/


// Good practice Question
// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j > 0; j--)
//         {
//             cout << j;
//         }
//         cout << endl;
//     }
    

//     return 0;
// }

/*
=====================================================
                  Pattern - 5
===================================================== 
*/

// Floyd's Triangle (numbers)

// int main(int argc, char const *argv[])
// {
//     int n,a;
//     cin >> n;

//     a = 1;

//         for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             cout << a;
//             a++;
//         }

//         cout << endl;
//         }
    
//     return 0;
// }

// Floyd's Triangle (chars)

// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;

//     char c;
//     cin >> c;



//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             cout << c;
//             c++;
//         }

//         cout << endl;
//         }
    
//     return 0;
// }

// Reverse Triangle (chars)

// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;

//     char c;
//     cin >> c; 

//     for (int i = 0; i < n; i++)
//     {
//         for (char ch = c + i; ch >= c; ch--) {
//             cout << ch << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

/*
=====================================================
                  Pattern - 6
===================================================== 
*/

// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;

//     char c;
//     cin >> c;

//     for (int i = 0; i < n; i++)
//     {
//         for (char j = 0; j < i + 1; j++)
//         {
//             cout << c << " ";
//             c++;
//         }

//         cout << endl;
        
//     }
    
//     return 0;
// }


/*
=====================================================
                  Pattern - 7
===================================================== 
*/

// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;

//     int num;
//     cin >> num;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <  i; j++)
//         {
//             cout <<  " ";
//         }
        
//         for (int k = 0; k < n - i; k++)
//         {
//             cout << i + 1;
//         }
        
//         cout << endl;
//     }
    
//     return 0;
// }

