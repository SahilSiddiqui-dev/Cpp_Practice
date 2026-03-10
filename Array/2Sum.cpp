#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr;
    vector<int> num;
    int n;
    cin >> n;
    int target;
    cin >> target;
    for(int i= 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        //int element = arr[i];
        for(int j = i + 1; j < n; j++){
            //THIS IS FOR ALL PAIRS : 
            //cout << "(" << element << "," << arr[j] << ")" ;
            
            if(arr[i] + arr[j] == target){
                cout << arr[i] << "," << arr[j];
                cout << endl;
            }

            
        }
    }
    return 0;
}
