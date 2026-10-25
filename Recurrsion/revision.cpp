#include <bits/stdc++.h>
using namespace std;

// int printing(int n) {
//     if(n == 0) return 0;

//     return n + printing(n - 1);
// }

// int factorial (int n) {
//     if(n == 1){
//         return 1;
//     }
//     return n*factorial(n-1);
// }

// bool reverse(int i, int j, vector<int>&arr){
//     if(i > j){
//         return true;
//     }
//     if(arr[i] != arr[j]){
//         return false;
//     }
//     return reverse(i + 1, j - 1, arr);
// }

void
int main() {
    vector<int>arr({1, 2, 1, 4});
    // int n;
    // cin >> n;
    cout << reverse(0, arr.size() - 1, arr);
    
}