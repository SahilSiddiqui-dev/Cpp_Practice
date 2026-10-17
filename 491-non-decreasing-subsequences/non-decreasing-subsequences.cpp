class Solution {
public:
    void solve(int i, int n, vector<int>&nums, vector<int>&current, vector<vector<int>>&ans) {
        if(current.size() >= 2) {
            ans.push_back(current);
        }

        unordered_set<int>st;

        for(int j = i; j < n; j++) {
            if((current.size() == 0 || current.back() <= nums[j]) && (st.find(nums[j]) == st.end())) {
                
                current.push_back(nums[j]);
                solve(j + 1, n, nums, current, ans);
                current.pop_back();

                st.insert(nums[j]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>current;
        vector<vector<int>>ans;
        int n = nums.size();
        solve(0, n, nums, current, ans);
        return ans;
    }
};