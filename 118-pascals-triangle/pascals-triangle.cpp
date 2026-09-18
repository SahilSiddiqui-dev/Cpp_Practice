class Solution {
public:

    int nCr(int n, int r) {
        long long result = 1;
        for(int i = 0; i < r; i++) {
            result = result * (n - i);
            result = result/(i+1);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        for(int i = 1; i <= numRows; i++) {
            vector<int>current;
            for(int j = 1; j <= i; j++) {
                int x = nCr(i - 1, j - 1);
                current.push_back(x);
                
            }
            ans.push_back(current);
        }
        return ans;
    }
};