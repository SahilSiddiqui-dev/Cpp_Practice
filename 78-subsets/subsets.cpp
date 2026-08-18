class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i, int n, vector<int>&nums, vector<int>&arr){
        if(i == n){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        solve(i + 1, n, nums, arr);

        arr.pop_back();
        solve(i + 1, n, nums, arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>arr;
        int n = nums.size();
        int i = 0;
        solve(i, n, nums,arr);
        return ans;
    }
};