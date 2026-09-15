class Solution {
public:

bool isSafe(vector<string>&board, int i, int j, int n) {

    for(int row = 0; row < i; row++){
        if(board[row][j] == 'Q')
            return false;
        
    }

    for(int col = j; col < n; col++) {
        if(board[i][col] == 'Q')
            return false;
    }

    for(int r = i, c = j; r >= 0 && c >= 0; r--, c--) {
        if(board[r][c] == 'Q')
            return false;
    }

    for(int r = i, c = j; r >= 0 && c < n; r--, c++) {
        if(board[r][c] == 'Q')
            return false;
    }

    return true;
}
void solve(vector<string>&board, int row, int n, vector<vector<string>>&ans) {
    if(row == n) {
        ans.push_back({board});
        return;
    }
    for(int j = 0; j < n; j++) {
        if(isSafe(board, row, j, n)) {
            board[row][j] = ('Q');
            solve(board, row + 1, n, ans);
            board[row][j] = ('.');
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n, '.'));
        vector<vector<string>>ans;
        solve(board, 0, n, ans);
        return ans;
    }
};