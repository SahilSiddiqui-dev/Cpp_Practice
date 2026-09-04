class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {

            int max_val =  INT_MIN;
            int min_val = INT_MAX;

        for(int s = 0; s <= i; s++) {
            max_val = max(max_val, nums[s]);
            }

        for(int j = i; j < n; j++){
                min_val = min(min_val, nums[j]);
            }

        if((max_val - min_val) <= k) {
                return i;
            }
        }

        return -1;
    }
};