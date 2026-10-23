class Solution {
public:
    int count;
    int K;
    void backtrack(int i, vector<int>&nums, unordered_map<int, int>&mp) {
        if(i >= nums.size()) {
            count++;
            return;
        }
        
        
        if(!mp[nums[i] + K] && !mp[nums[i] - K]) {
            mp[nums[i]]++;
            backtrack(i + 1, nums, mp);
            mp[nums[i]]--;
        }
        backtrack(i + 1, nums, mp);

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        count = 0;
        K = k;
        backtrack(0, nums, mp);
        return count - 1;
    }
};