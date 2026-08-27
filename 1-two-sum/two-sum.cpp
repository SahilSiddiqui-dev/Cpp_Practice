class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if(!mp.contains(x)){
                mp[nums[i]] = i;
            }
            else {
                return {i,mp[x]};
            }
        }
        return {};
    }
};