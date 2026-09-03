class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        bool ans = false;
        int min_val = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            min_val = min(min_val, nums[i]);
            if(nums[i] % 2 != 0){
                
                ans = true;
            }
        }
        if(!ans){
            return true;
        }
        if(min_val %2 != 0) return true;
        return false;
    }
};