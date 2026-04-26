#include <bits/stdc++.h>
using namespace std;
void subset(int idx, int n, vector<int>&arr, vector<vector<int>>&ans, vector<int>temp){
    if(idx == n){
        ans.push_back(temp);
        return;
    }
    subset(idx + 1, n, arr, ans, temp);
    temp.push_back(arr[idx]);
    subset(idx + 1, n, arr, ans, temp);
    
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }
    vector<int>temp;
    vector<vector<int>>ans;
    subset(0, n, arr, ans, temp);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout  << ans[i][j] << " ";
        }
        cout << endl;
    }
    

}