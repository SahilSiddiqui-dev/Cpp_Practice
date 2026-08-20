#include <bits/stdc++.h>
using namespace std;

void even(int n){
    if(n%2 != 0){
        n -= 1;
    }
    if(n == 2){
        cout << n << " ";
        return;
    }
    even(n - 1);
    cout << n << " ";
    
    
    
}
int main(){
    int n;
    cin >> n;
    even(n);
}