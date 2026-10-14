class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if (sum > 9*num) return "";

        for(int i = 0; i < num; i++){
            int take = min(sum, 9);
            ans += to_string(take);
            sum -= take;
        }

     
        return ans;
    }
};