#include <bits/stdc++.h>
using namespace std;
string convertToUpper(string str, int i){
    if(i == -1){
        return str;
    }

    str[i] = 'A' + (str[i] - 'a');

    return convertToUpper(str, i - 1);
}
int main() {
    string str;
    cin >> str;
    int n = str.size();
    cout << convertToUpper(str, n - 1);
}