#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    int s = 0;
    int e = size - 1;
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    for(int i = 0; i <= 5; i++){
        cout << arr[i];
    }
    return 0;
  }