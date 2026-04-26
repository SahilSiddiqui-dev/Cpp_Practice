#include <bits/stdc++.h>
using namespace std;

bool is_it_safe(int node, int n, int col, vector<vector<int>>&graph, vector<int>&color){
    for(int i = 0 ; i <n ; i++){
        if(graph[node][i] == 1 && color[i] == col){
            return false;  // Conflict found, not safe
        }
    }
    return true;  // No conflict, safe to use this color
}

bool solve(int node, int n, int m, vector<vector<int>>&graph, vector<int>&color){
    if(node == n) return true;

    for(int col = 1; col < m; col++){

        if(is_it_safe(node, n, col, graph, color))
            color[node] = col;
    
        if(solve(node + 1, n, m, graph, color))
        return true;

        color[node] = 0;
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>graph(n, vector<int>(n));
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    vector<int>color(n, 0);
    if(solve(0, n, m, graph, color)){
        cout << "solution is available" << endl;
    }
    else{
        cout << "not available" << endl;
    }
}