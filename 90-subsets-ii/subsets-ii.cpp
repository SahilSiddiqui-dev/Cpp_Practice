class Solution {
public:
    set<vector<int>>ans;
    void solve(int i, int n, vector<int>&nums, vector<int>&arr){
        if(i == n){
                ans.insert(arr);
                return;
        }

        arr.push_back(nums[i]);
        solve(i + 1, n, nums, arr);

        arr.pop_back();
        solve(i + 1, n, nums, arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>arr;
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        solve(i, n, nums,arr);
        vector<vector<int>>ans1(ans.begin(), ans.end());
        return ans1;
    }
};