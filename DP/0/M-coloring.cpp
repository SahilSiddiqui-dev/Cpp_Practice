#include <bits/stdc++.h>
using namespace std;
bool is_it_safe(int node, vector<vector<int>>&adj, vector<int>&col, int c){
    for(int neighbour : adj[node]){
        if(col[neighbour] == c){
            return false;
        }
    }
    return true;
}
bool solve(int v, int n, int m, vector<vector<int>>&adj, vector<int>&col){
    if(n == v){
        return true;
    }
    for(int i = 0; i< m; i++){
        if(is_it_safe(v, adj, col, i)){
            col[v] = i;

            if(solve(v + 1, n, m, adj, col))
            return true;

        col[v] = 0;
    }
}
    return false;

}

 int main(){
    int n, e, m;
    cin >> n >> e >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i< e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> col(n, 0);
    if(solve(0, n, m, adj, col)){
        cout << "solution available"<< endl;
    }

    else {
        cout << "no solution" << endl;
    }
    return 0;
 }