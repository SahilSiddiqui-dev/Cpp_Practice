class Solution {
public:
    bool check(vector<int>&current, int n) {
        int s = 0;
        for(int i = 0; i < current.size(); i++) {
            s += current[i];
        }
        if(s == n) return true;
        return false;
    }

    void solve(int i, int k, int n, vector<int>&current, vector<vector<int>>&ans) {
        if(current.size() == k) {
            if(n == 0) {
                ans.push_back(current);
                return;
            }
        }

        for(int j = i; j <= 9; j++) {
            current.push_back(j);
            solve(j + 1, k, n - j, current, ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        vector<vector<int>>ans;
        solve(1, k, n, current, ans);
        return ans;
        
    }
};