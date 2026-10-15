class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            set<int>ans;
            for(int j = i; j < nums.size(); j++) {
                ans.insert(nums[j]);
                int x = ans.size();
                sum += x*x;
            }
        }
        return sum;
    }
};