class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i, int n, vector<int>& nums){
        if(i == n){
            ans.push_back(nums);
            return;
        }
        for(int j = i; j < n; j++){
            swap(nums[i], nums[j]);
            solve(i+1, n, nums);
            swap(nums[i], nums[j]);
        }
    }     
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        solve(i, n, nums);
        return ans;
    }
};