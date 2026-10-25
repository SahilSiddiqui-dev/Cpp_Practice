#include <bits/stdc++.h>
using namespace std;

int Power(int n) {
    if(n == 1){
        return 2;
    }
    return 2*Power(n-1);

}
int main(){
    int n;
    cin >> n;
    cout << Power(n);
}