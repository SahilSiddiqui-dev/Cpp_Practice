class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>arr;
        
        long long sum = 0;
        int n = nums.size();
        int i = 0;
        int j = n - 1;

        for(int k = 0; k < n; k++){
            long long x = nums[k]*nums[k];
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());
        while(i < j) {
                sum += arr[j];
                sum -= arr[i];
                i++;
                j--;
            }
            // else {
            //     sum -= arr[j];
            //     sum += arr[i];
            //     i++;
            //     j--;
            // }
                if(i == j){
            sum += arr[i];
        }
        return sum;
    }
};