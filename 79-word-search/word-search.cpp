class Solution {
public:
    bool solve(int i, int j, int k, vector<vector<char>>&board, string&word) {
        if(k == word.size()) return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k]) return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = solve(i, j + 1, k + 1, board, word) ||
                     solve(i + 1, j, k + 1, board, word) ||
                     solve(i, j - 1, k + 1, board, word) ||
                     solve(i - 1, j, k + 1, board, word);
                     
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int s = 0; s < board.size(); s++) {
            for(int e = 0; e < board[0].size(); e++){
                if(board[s][e] == word[0] && solve(s, e, 0, board, word)) return true;
            }

        }
        return false;
    }
};