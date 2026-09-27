class Solution {
public:
    void solve(int i, vector<int>&current, vector<int>& nums, vector<vector<int>>&ans) {
        if(i == nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        solve(i + 1, current, nums, ans);

        current.pop_back();
        solve(i+1, current, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>current;
        solve(0, current, nums, ans);
        return ans;
    }
};