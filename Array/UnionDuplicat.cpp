#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main(){

    vector<int> brr{1, 2, 3, 5, 7};
    vector<int> arr{3, 5, 3, 8, 9};
    vector<int> ans;

    for(int j = 0; j < brr.size(); j++){
        for(int i= 0; i < arr.size(); i++){
            if(brr[j] == arr[j]){
            arr[j] = INT_MIN;
            }
            
        }
    }
    for(int i =0; i< arr.size() + brr.size(); i++){
        ans.push_back(brr[i]);
        if(arr[i] != INT_MIN){
        ans.push_back(arr[i]);
       }

    }
    
    for(int i =0; i< arr.size(); i++){
        cout << ans[i]<< " ";

    }

}