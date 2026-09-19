class Solution {
public:
    bool isSafe(int i, int j, char x, vector<vector<char>>& board){
        for(int row = 0; row < 9; row++) {
            if(board[row][j] == x) return false;
        }
        for(int col = 0; col < 9; col++) {
            if(board[i][col] == x) return false;
        }

        int startRow = 3*(i/3);
        int startCol = 3*(j/3);

        for(int row = startRow; row < startRow+3; row++){
            for(int col = startCol; col < startCol+3; col++){
                if(board[row][col] == x) return false;
            }
        }
        return true;
    }

    bool solve(int row, int col, vector<vector<char>>& board) {

        if(row == 9) {
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;
        if(nextCol == 9){
            nextCol = 0;
            nextRow = row + 1;
        }

        if(board[row][col] != '.'){
            return solve(nextRow, nextCol, board);
        }


       for(char c = '1'; c <= '9'; c++){
            if(isSafe(row, col, c, board)) {
                board[row][col] = c;
                if(solve(nextRow, nextCol, board)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
        
    }
    


    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(0, 0, board);
    }
};