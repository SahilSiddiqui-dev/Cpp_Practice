#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int ans = 0 ;
    for(int i = 0; i < arr.size(); i++){
        ans = arr[i]^ans;
    }
    cout << ans;
}