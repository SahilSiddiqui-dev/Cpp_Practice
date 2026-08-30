class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = distance( nums.begin(), min_element(nums.begin(), nums.end()));
        int maxi = distance( nums.begin(), max_element(nums.begin(), nums.end()));
        int n = nums.size();
        int left = min(mini, maxi);
        int right = max(mini, maxi);
        int first = right + 1;
        int second =   n - left;
        int third = (left + 1) + (n - right);
       return min({first, second, third});




    }
};