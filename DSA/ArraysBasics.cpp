#include<bits/stdc++.h>
using namespace std;

// Find the min. num  
// int main() {

//     int nums[5] = {1, 2, 4, 5, 6};

//     int size = sizeof(nums) / sizeof(nums[0]);
//     int sm = INT_MAX;

//     for (int i = 0; i < size; i++)
//     {
//         if (nums[i] < sm)
//         {
//             sm = nums[i];
//         }
//     }

//     cout << sm << endl;
    
//     return 0;
// }

// =====================================================

// Reverse the Array

void ReverseArray(int arr[],int size){
    int start = 0, end = size - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ReverseArray(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
