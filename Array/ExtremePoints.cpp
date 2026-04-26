#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr [] = {1, 3, 5, 9, 6, 7, 8};
    int size = 7;
    int s = 0 ; 
    int e = size  - 1;
    while(s <= e ){
        if(s == e) {
            cout << arr[s];
        }
        else 
        {
        cout << arr[s] << ',';
        cout << arr[e] << ',';
        
    }
    s++;
        e--;
    }

}