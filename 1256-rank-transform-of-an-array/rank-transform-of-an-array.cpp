class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>nums = arr;
        sort(nums.begin(), nums.end());
        int rank = 1;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = rank;
                rank++;
            }
        }

        for(int&x : arr){
           x = mp[x];
        }
        return arr;
    }
};