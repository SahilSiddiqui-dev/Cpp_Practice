#include <bits/stdc++.h>
using namespace std;
bool search(int arr[], int i, int target, int n){
    if(i == n){
        return false;
    }
    if(arr[i] == target){
        return true;
    }
    return search(arr, i + 1, target, n);
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << search(arr, 0, 8, n);
}