#include <bits/stdc++.h>
using namespace std;
int count(string str, int i){
    if(i == -1){
        return 0;
    }
    if(str[i] == 'a' || str[i] == 'i'  || str[i] == 'o' ||  str[i] == 'e'  || str[i] == 'u'){
        return 1 + count(str, i - 1);
    }
    else {
        return count(str, i - 1);
    }   
}
int main(){
    string str;
    cin >> str;
    int n = str.size();

    cout << count(str, n - 1);
    
}