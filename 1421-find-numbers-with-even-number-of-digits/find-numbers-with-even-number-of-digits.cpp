class Solution {
public:

    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            string x = to_string(nums[i]);
            int s = x.size();
            if(s%2 == 0) {
                count++;
            }
        }
        return count;
    }
};