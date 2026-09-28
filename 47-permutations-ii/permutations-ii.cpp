class Solution {
public:
    set<vector<int>>ans;
    void solve(int i, vector<int>&nums, set<vector<int>>&ans) {
        if(i == nums.size()){
            ans.insert(nums);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            swap(nums[j] , nums[i]);
            solve(i+1, nums, ans);
            swap(nums[j], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0, nums, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};