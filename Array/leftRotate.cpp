#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    vector<int> arr{1, 2, 3, 5, 6};
    vector<int> num;
    //THIS IS FOR RIGHT ROTATED ARRAY
    // num.push_back(arr[arr.size()-1]);
    for(int i = 1; i < arr.size(); i++){
        num.push_back(arr[i]);
    }
    num.push_back(arr[0]);
    for(int i = 0; i < num.size(); i++){
        cout << num[i] << " ";
    }
}