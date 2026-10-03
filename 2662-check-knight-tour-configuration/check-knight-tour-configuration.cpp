class Solution {
public:
    bool solve(int r, int c, int n, int find, vector<vector<int>>&grid){
        if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != find){
            return false;
        }
        if(find == n*n - 1) {
            return true;
        }

        int ans1 = solve(r-2, c+1, n, find +1, grid);
        int ans2 = solve(r-1, c+2, n, find +1, grid);
        int ans3 = solve(r+1, c+2, n, find +1, grid);
        int ans4 = solve(r+2, c+1, n, find +1, grid);
        int ans5 = solve(r+2, c-1, n, find +1, grid);
        int ans6 = solve(r+1, c-2, n, find +1, grid);
        int ans7 = solve(r-1, c-2, n, find +1, grid);
        int ans8 = solve(r-2, c-1, n, find +1, grid);
        
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(0, 0, n, 0, grid);
    
    }
};
