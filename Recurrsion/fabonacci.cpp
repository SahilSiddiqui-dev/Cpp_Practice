#include <bits/stdc++.h>
using namespace std;

int fabonacci(int n){
    if(n <= 1){
        return 1;
    }
    return fabonacci( n-1) + fabonacci(n-2);
}
int main(){
    int n;
    cin >> n;
    cout << fabonacci(n);
}