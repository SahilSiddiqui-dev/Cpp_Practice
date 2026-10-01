class Solution {
public:
    bool isSafe(int i, int j, int n, vector<string>&board) { 
        for(int row = 0; row <= i; row++){
            if(board[row][j] == 'Q') return false;
        }
        for(int row = i, col = j; row >= 0 && col >= 0; row--, col--){
            if(board[row][col] == 'Q') return false;
        }
        for(int row = i, col = j; row >= 0 && col < n; row--, col++) {
            if(board[row][col] == 'Q') return false;
        }
        return true;
    }
    void solve(int i, int n, vector<string>&board, vector<vector<string>>&ans) { 
        if(i == n){
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(isSafe(i, j, n, board)) {
                board[i][j] = 'Q';
                solve(i + 1, n, board, ans);
                board[i][j] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n ,'.'));
        vector<vector<string>>ans;
        solve(0, n, board, ans);
        return ans;
    }
};