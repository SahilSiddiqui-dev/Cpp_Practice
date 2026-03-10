#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int> > arr(5, vector<int>(5 , -8));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size() ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << arr[3][2] << endl;;
    cin >> arr[3][4];
    cout << arr[3][4];
}