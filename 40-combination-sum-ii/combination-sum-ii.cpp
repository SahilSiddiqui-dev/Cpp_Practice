class Solution {
public:
    void solve(int i, vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>&arr) {
          if(target == 0){
            ans.push_back(arr);
            return;
        }
        for(int j = i; j < candidates.size(); j++) {
            if(j > i && candidates[j] == candidates[j - 1]) continue;

            if(candidates[j] > target) break;

            arr.push_back(candidates[j]);
            solve(j + 1, candidates, target - candidates[j], ans, arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0, candidates, target, ans, arr);
        return ans;
    }
};