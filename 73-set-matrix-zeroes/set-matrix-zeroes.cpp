class Solution {
public:

    void solve(int i, int j, int n, int m, vector<vector<int>>&matrix, vector<vector<int>>&visited) {
        
        for(int y = 0; y < m; y++){
            if(matrix[i][y] != 0){
                visited[i][y] = 1;
                matrix[i][y] = 0;
            }
        }

        for(int x = 0; x < n; x++) {
            if(matrix[x][j] != 0) {
                visited[x][j] = 1;
                matrix[x][j] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0 && visited[i][j] == 0){
                    solve(i, j, n, m, matrix, visited);
                }
            }
        }
        
    }
};