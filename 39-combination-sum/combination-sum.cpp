class Solution {
public: 
    set<vector<int>>s;
    void solve(int i, vector<int>&arr, vector<int>& candidates, int target, vector<vector<int>>&ans) {
        
        if (target == 0){
            if(s.find(arr) == s.end()){
                ans.push_back(arr);
                s.insert(arr);
            }
            
            return;
        }

        if(i == candidates.size() || target < 0) return;

        arr.push_back(candidates[i]);
        solve(i + 1, arr, candidates, target - candidates[i], ans);
        solve(i, arr, candidates, target - candidates[i], ans);
        arr.pop_back();
        solve(i + 1, arr, candidates, target, ans);
    

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0, arr, candidates, target, ans);
        return ans;

    }
};