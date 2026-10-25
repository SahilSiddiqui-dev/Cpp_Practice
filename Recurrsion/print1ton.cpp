#include <bits/stdc++.h>
using namespace std;

void print1(int n){
    if(n == 1){
        cout << n << " ";
        return;
    }
    print1(n - 1);
    cout << n << " ";
}
int main(){
    int n;
    cin >> n;
    print1(n);
}