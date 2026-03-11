#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    vector<int> brr{1, 3, 3, 4, 7};
    vector<int> arr{1, 3, 4, 3, 7};
    vector<int> ans; //{1, 3, 4}
    
    for(int i = 0; i < arr.size(); i++){
       for(int j = 0; j < brr.size(); j++){
        if(arr[i] == brr[j]){
            brr[j]= -1;
            ans.push_back(arr[i]);
            
            }
        }
    }
    
    for(int i =0; i< ans.size(); i++){
        cout << ans[i] << " ";

    }
}