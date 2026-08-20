#include <bits/stdc++.h>
using namespace std;
string reverse(string str, int start, int end){
   if(start >= end){
    return str;
   }
   swap(str[start], str[end]);
   return reverse(str, start + 1, end - 1);
}
int main(){
    string str;
    cin >> str;
    int n = str.size();

    cout << reverse(str, 0, n - 1);
    
}