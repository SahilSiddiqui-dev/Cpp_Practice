class Solution {
public:
    long long ncr(int n, int r){
        long long result = 1;
        for(int i = 0; i < r; i++){
            result *= n-i;
            result /= i+1;
        }

        return result;
    }
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        for(int i = 0; i <= rowIndex; i++){
            ans.push_back(ncr(rowIndex, i));
        }
        return ans;
    }
};