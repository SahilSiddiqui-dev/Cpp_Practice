class Solution {
public:
    bool isSafe(int i, int j, int n, vector<string>&board){

        for(int row = 0; row < i; row++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        for(int col = j; col < n; col++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int row = i, col = j; row >= 0 && col >= 0; row--, col--){
            if(board[row][col] == 'Q') return false;
        }

        for(int row = i, col = j; row >= 0 && col < n; row--, col++){
            if(board[row][col] == 'Q') return false;
        }

        return true;
    }

    void solve(int i, int n, vector<string>&nqueen, vector<vector<string>>&ans){
        if(i == n){
            ans.push_back(nqueen);
            return;
        }

        for(int j = 0; j < n; j++){
            if(isSafe(i, j, n, nqueen)){
                nqueen[i][j] = 'Q';
                solve(i + 1, n, nqueen, ans);
                nqueen[i][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>nqueen(n, string(n, '.'));
        vector<vector<string>>ans;
        solve(0, n, nqueen, ans);
        return ans.size();
        
        
    }
};