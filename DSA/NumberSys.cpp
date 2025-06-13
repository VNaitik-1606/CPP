#include <iostream>
using namespace std;

/*
=====================================================
                    Decimal to Binary
===================================================== 
*/

// void decimalToBinary(int n) {
//     if (n == 0) {
//         cout << "0";
//         return;
//     }
    
//     int binary = 0;
//     int place = 1;
    
//     while (n > 0) {
//         int remainder = n % 2;
//         binary += remainder * place;
//         place *= 10;
//         n /= 2;
//     }
    
//     cout << binary;
// }

// int main() {
//     int decimalNumber;
    
//     cout << "Enter a decimal number: ";
//     cin >> decimalNumber;
    
//     cout << "Binary equivalent: ";
//     decimalToBinary(decimalNumber);
    
//     return 0;
// }

/*
=====================================================
                    Binary to Decimal 
===================================================== 
*/

void binaryToDecimal(int n) {
    if (n == 0) {
        cout << "0";
        return;
    }
    
    int decimal = 0;
    int place = 1;
    
    while (n > 0) {
        int remainder = n % 10;
        decimal += remainder * place;
        place *= 10;
        n /= 10;
    }
    
    cout << decimal;
}

int main() {
    int binaryNumber;
    
    cout << "Enter a binary number: ";
    cin >> binaryNumber;
    
    cout << "Binary equivalent: ";
    binaryToDecimal(binaryNumber);
    
    return 0;
}