#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> num(n, 0);
   
    for(int i= 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        num[arr[i]]++;
    }
    int maxi = INT_MIN;
    for(auto j : num){
        cout << j << " ";
    }
    cout << endl;
    for(auto i : num){
        maxi = max(i, i + 1);
    
    }
    cout << maxi;
    return 0;
}
