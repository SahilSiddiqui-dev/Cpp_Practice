#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> brr;
    vector<int> arr;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        brr.push_back(a);
    }
    for(int i = 0; i < arr.size(); i++){
        ans.push_back(arr[i]);
    }
    for(int i = 0; i < brr.size(); i++){
        ans.push_back(brr[i]);
    }
    for(int i =0; i< ans.size(); i++){
        cout << ans[i] << " ";

    }
}