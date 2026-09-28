class Solution {
public:
    void solve(int i, vector<int>&nums, vector<vector<int>>&ans) {
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>seen;
        
        for(int j = i; j < nums.size(); j++){

            if(seen.count(nums[j])) continue;
            seen.insert(nums[j]);
            swap(nums[j] , nums[i]);
            solve(i+1, nums, ans);
            swap(nums[j], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0, nums, ans);
        return ans;
    }
};